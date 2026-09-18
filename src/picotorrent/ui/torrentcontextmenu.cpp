#include "torrentcontextmenu.hpp"

#include <filesystem>
#include <fstream>

#include <libtorrent/add_torrent_params.hpp>
#include <libtorrent/torrent_status.hpp>
#include <libtorrent/write_resume_data.hpp>
#include <wx/clipbrd.h>

#include "../bittorrent/magneturi.hpp"
#include "../bittorrent/torrenthandle.hpp"
#include "../bittorrent/torrentstatus.hpp"
#include "../core/configuration.hpp"
#include "../core/utils.hpp"
#include "dialogs/textoutputdialog.hpp"
#include "translator.hpp"

namespace fs = std::filesystem;
using pt::UI::Dialogs::TextOutputDialog;
using pt::UI::TorrentContextMenu;

TorrentContextMenu::TorrentContextMenu(wxWindow* parent, std::shared_ptr<pt::Core::Configuration> cfg, std::vector<pt::BitTorrent::TorrentHandle*> const& selectedTorrents)
    : wxMenu(),
    m_parent(parent)
{
    wxMenu* queueMenu = new wxMenu();
    queueMenu->Append(ptID_QUEUE_UP, i18n("up"));
    queueMenu->Append(ptID_QUEUE_DOWN, i18n("down"));
    queueMenu->AppendSeparator();
    queueMenu->Append(ptID_QUEUE_TOP, i18n("top"));
    queueMenu->Append(ptID_QUEUE_BOTTOM, i18n("bottom"));

    wxMenu* removeMenu = new wxMenu();
    removeMenu->Append(ptID_REMOVE, i18n("remove_torrent"));
    removeMenu->Append(ptID_REMOVE_FILES, i18n("remove_torrent_and_files"));

    wxMenu* exportMenu = new wxMenu();
    exportMenu->Append(ptID_EXPORT_MAGNET_LINK, i18n("magnet_link_s"));
    exportMenu->Append(ptID_EXPORT_TORRENT_FILE, i18n("torrent_file_s"));

    bool allPaused = std::all_of(
        selectedTorrents.begin(),
        selectedTorrents.end(),
        [](BitTorrent::TorrentHandle* torrent)
        {
            return torrent->Status().paused;
        });

    bool allNotPaused = std::all_of(
        selectedTorrents.begin(),
        selectedTorrents.end(),
        [](BitTorrent::TorrentHandle* torrent)
        {
            return !torrent->Status().paused;
        });

    wxMenuItem* resume = Append(ptID_RESUME, i18n("resume"));
    wxMenuItem* resumeForced = Append(ptID_RESUME_FORCE, i18n("resume_force"));
    wxMenuItem* pause = Append(ptID_PAUSE, i18n("pause"));

    if (allPaused)
    {
        Delete(pause);
    }

    if (allNotPaused)
    {
        Delete(resume);
        Delete(resumeForced);
    }

    AppendSeparator();
    Append(ptID_FORCE_REANNOUNCE, i18n("force_reannounce"));
    Append(ptID_FORCE_RECHECK, i18n("force_recheck"));

    if (selectedTorrents.size() == 1)
    {
        AppendSeparator();

        BitTorrent::TorrentHandle* t = selectedTorrents.at(0);

        wxMenuItem* item = Append(ptID_SEQUENTIAL_DOWNLOAD, i18n("sequential_download"));
        item->SetCheckable(true);
        item->Check(t->IsSequentialDownload());
    }

    // Labels
    auto labels = cfg->GetLabels();

    if (labels.size() > 0)
    {
        AppendSeparator();
        wxMenu* labelsMenu = new wxMenu();

        if (selectedTorrents.size() == 1)
        {
            wxMenuItem* noneItem = labelsMenu->AppendRadioItem(ptID_LABELS_NONE, i18n("none"));

            if (selectedTorrents.at(0)->Label() < 0)
            {
                noneItem->Check(true);
            }
        }
        else
        {
            labelsMenu->Append(ptID_LABELS_NONE, i18n("none"));
        }

        for (auto const& label : labels)
        {
            if (selectedTorrents.size() == 1)
            {
                labelsMenu->AppendRadioItem(ptID_LABELS_USER + label.id, Utils::toStdWString(label.name))
                    ->Check(selectedTorrents.at(0)->Label() == label.id);
            }
            else
            {
                labelsMenu->Append(ptID_LABELS_USER + label.id, Utils::toStdWString(label.name));
            }

            m_labels.insert({ label.id, label.name });
        }

        AppendSubMenu(labelsMenu, i18n("label"));
    }

    AppendSeparator();
    AppendSubMenu(exportMenu, i18n("export"));
    Append(ptID_MOVE, i18n("move"));
    AppendSubMenu(removeMenu, i18n("remove"));
    AppendSeparator();
    AppendSubMenu(queueMenu, i18n("queuing"));
    AppendSeparator();
    Append(ptID_COPY_INFO_HASH, i18n("copy_info_hash"));
    Append(ptID_OPEN_IN_EXPLORER, i18n("open_in_explorer"));

    // Bind events
    Bind(
        wxEVT_MENU,
        [&](wxCommandEvent&) { for (auto t : selectedTorrents) { t->Resume(); } },
        TorrentContextMenu::ptID_RESUME);

    Bind(
        wxEVT_MENU,
        [&](wxCommandEvent&) { for (auto t : selectedTorrents) { t->ResumeForce(); } },
        TorrentContextMenu::ptID_RESUME_FORCE);

    Bind(
        wxEVT_MENU,
        [&](wxCommandEvent&) { for (auto t : selectedTorrents) { t->Pause(); } },
        TorrentContextMenu::ptID_PAUSE);

    Bind(
        wxEVT_MENU,
        [&](wxCommandEvent&)
        {
            std::stringstream ss;

            for (auto torrent : selectedTorrents)
            {
                ss << BitTorrent::makeMagnetUri(torrent->WrappedHandle()) << "\n";
            }

            TextOutputDialog dlg(m_parent, wxID_ANY, i18n("magnet_link_s"), i18n("exported_magnet_link_s"));
            dlg.SetOutputText(ss.str());
            dlg.ShowModal();
        },
        TorrentContextMenu::ptID_EXPORT_MAGNET_LINK);

    Bind(
        wxEVT_MENU,
        [&](wxCommandEvent&)
        {
            wxDirDialog dlg(
                m_parent,
                i18n("select_destination"),
                wxEmptyString,
                wxDD_DIR_MUST_EXIST);

            if (dlg.ShowModal() != wxID_OK)
            {
                return;
            }

            fs::path outputDir = Utils::toStdString(dlg.GetPath().ToStdWstring());

            for (auto torrent : selectedTorrents)
            {
                // libtorrent 2.1 removed torrent_handle::torrent_file_with_hashes
                // together with the torrent_info-based create_torrent. The
                // replacement is write_torrent_file() on an add_torrent_params.
                lt::torrent_status ts = torrent->WrappedHandle().status(
                    lt::torrent_handle::query_torrent_file);

                auto src = ts.torrent_file.lock();
                if (!src) { continue; }

                lt::add_torrent_params atp;
                atp.ti = src;

                for (lt::announce_entry const& ae : torrent->WrappedHandle().trackers())
                {
                    atp.trackers.push_back(ae.url);
                }

                for (std::string const& s : torrent->WrappedHandle().url_seeds())
                {
                    atp.url_seeds.push_back(s);
                }

                atp.comment = torrent->Status().comment;

                // merkle_trees wants whole trees (root first), piece_layers()
                // hands out just the piece layer - write_torrent_file() threw
                // on every v2/hybrid torrent. Write the layers ourselves, keyed
                // by file root the way BEP 52 lays them out.
                lt::entry e = lt::write_torrent_file(atp, lt::write_flags::allow_missing_piece_layer);

                auto const layers = torrent->WrappedHandle().piece_layers();
                lt::file_storage const& fs = src->layout();

                for (lt::file_index_t f : fs.file_range())
                {
                    int const i = static_cast<int>(f);

                    if (fs.pad_file_at(f)
                        || fs.file_size(f) <= fs.piece_length()
                        || i >= static_cast<int>(layers.size())
                        || static_cast<int>(layers[i].size()) != fs.file_num_pieces(f))
                    {
                        continue;
                    }

                    std::string& layer = e["piece layers"][fs.root(f).to_string()].string();

                    for (lt::sha256_hash const& h : layers[i])
                    {
                        layer += h.to_string();
                    }
                }

                std::string fileName = src->name() + ".torrent";
                std::ofstream out(outputDir / fileName, std::ios::binary);
                lt::bencode(std::ostreambuf_iterator<char>(out), e);
            }
        },
        TorrentContextMenu::ptID_EXPORT_TORRENT_FILE);

    Bind(
        wxEVT_MENU,
        [&](wxCommandEvent&)
        {
            wxDirDialog dlg(
                m_parent,
                i18n("select_destination"),
                wxEmptyString,
                wxDD_DIR_MUST_EXIST);

            if (dlg.ShowModal() != wxID_OK)
            {
                return;
            }

            for (auto torrent : selectedTorrents)
            {
                torrent->MoveStorage(
                    Utils::toStdString(
                        dlg.GetPath().ToStdWstring()));
            }
        },
        TorrentContextMenu::ptID_MOVE);

    Bind(
        wxEVT_MENU,
        [&](wxCommandEvent&) { for (auto torrent : selectedTorrents) { torrent->Remove(); } },
        TorrentContextMenu::ptID_REMOVE);

    Bind(
        wxEVT_MENU,
        [&](wxCommandEvent&)
        {
            if (wxMessageBox(
                i18n("confirm_remove_description"),
                i18n("confirm_remove"),
                wxOK | wxCANCEL | wxICON_INFORMATION,
                m_parent) != wxOK) { return; }

            for (auto torrent : selectedTorrents) { torrent->RemoveFiles(); }
        },
        TorrentContextMenu::ptID_REMOVE_FILES);

    Bind(
        wxEVT_MENU,
        [&](wxCommandEvent&) { for (auto torrent : selectedTorrents) { torrent->QueueUp(); } },
        TorrentContextMenu::ptID_QUEUE_UP);

    Bind(
        wxEVT_MENU,
        [&](wxCommandEvent&) { for (auto torrent : selectedTorrents) { torrent->QueueDown(); } },
        TorrentContextMenu::ptID_QUEUE_DOWN);

    Bind(
        wxEVT_MENU,
        [&](wxCommandEvent&) { for (auto torrent : selectedTorrents) { torrent->QueueTop(); } },
        TorrentContextMenu::ptID_QUEUE_TOP);

    Bind(
        wxEVT_MENU,
        [&](wxCommandEvent&) { for (auto torrent : selectedTorrents) { torrent->QueueBottom(); } },
        TorrentContextMenu::ptID_QUEUE_BOTTOM);

    Bind(
        wxEVT_MENU,
        [&](wxCommandEvent&)
        {
            std::stringstream ss;
            for (auto torrent : selectedTorrents)
            {
                ss << ",";
                if (torrent->InfoHash().has_v2()) { ss << torrent->InfoHash().v2; }
                if (torrent->InfoHash().has_v1()) { ss << torrent->InfoHash().v1; }
            }

            if (wxTheClipboard->Open())
            {
                wxTheClipboard->SetData(new wxTextDataObject(ss.str().substr(1)));
                wxTheClipboard->Close();
            }
        },
        TorrentContextMenu::ptID_COPY_INFO_HASH);

    Bind(
        wxEVT_MENU,
        [&](wxCommandEvent&)
        {
            auto torrent = selectedTorrents.front();
            auto status = torrent->Status();

            fs::path savePath = wxString::FromUTF8(status.savePath).ToStdWstring();
            fs::path path = savePath / wxString::FromUTF8(status.name).ToStdWstring();

            Utils::openAndSelect(path);
        },
        TorrentContextMenu::ptID_OPEN_IN_EXPLORER);

    Bind(
        wxEVT_MENU,
        [&](wxCommandEvent&) { for (auto torrent : selectedTorrents) { torrent->ForceRecheck(); } },
        TorrentContextMenu::ptID_FORCE_RECHECK);

    Bind(
        wxEVT_MENU,
        [&](wxCommandEvent&) { for (auto torrent : selectedTorrents) { torrent->ForceReannounce(); } },
        TorrentContextMenu::ptID_FORCE_REANNOUNCE);

    Bind(
        wxEVT_MENU,
        [&](wxCommandEvent& evt) { for (auto torrent : selectedTorrents) { torrent->SetSequentialDownload(evt.IsChecked()); } },
        TorrentContextMenu::ptID_SEQUENTIAL_DOWNLOAD);

    Bind(
        wxEVT_MENU,
        [&](wxCommandEvent& evt)
        {
            if (evt.GetId() != ptID_LABELS_NONE
                && evt.GetId() < ptID_LABELS_USER)
            {
                evt.Skip();
                return;
            }

            // handle others - i.e labels
            switch (evt.GetId())
            {
            case ptID_LABELS_NONE:
            {
                for (auto torrent : selectedTorrents) { torrent->ClearLabel(); }
                break;
            }
            }

            if (evt.GetId() > ptID_LABELS_USER)
            {
                int id = evt.GetId() - ptID_LABELS_USER;
                for (auto torrent : selectedTorrents) { torrent->SetLabel(id, m_labels.at(id)); }
            }
        });
}
