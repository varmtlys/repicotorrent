#include "preferencesadvancedpage.hpp"

#include <map>

#include <wx/propgrid/manager.h>
#include <wx/propgrid/propgrid.h>

#include "../../core/configuration.hpp"
#include "../translator.hpp"

using pt::Core::Configuration;
using pt::UI::Dialogs::PreferencesAdvancedPage;

struct Property
{
    std::function<wxPGProperty*()> ctor;
    std::function<void(Configuration*, wxPGProperty*)> get;
    std::function<void(Configuration*, wxPGProperty*)> set;
};

// The description of each setting is the translation key
// "advanced_desc_<label>".
#define MAKE_PROP(t1, t2, t3, key, label) \
    { \
        label, \
        { \
            []() { return new wx ##t1 ##Property(label); },\
            [](Configuration* cfg, wxPGProperty* prop) { if (auto v = cfg->Get<##t3>(key)) { prop->SetValue(v.value()); } }, \
            [](Configuration* cfg, wxPGProperty* prop) { cfg->Set(key, prop->GetValue().Get ##t2()); } \
        } \
    }

static std::map<std::string, std::map<std::string, Property>> properties =
{
    {
        "libtorrent",
        {
            MAKE_PROP(Int,      Integer,    int,            "libtorrent.active_checking", "active_checking"),
            MAKE_PROP(Int,      Integer,    int,            "libtorrent.active_dht_limit", "active_dht_limit"),
            MAKE_PROP(Int,      Integer,    int,            "libtorrent.active_lsd_limit", "active_lsd_limit"),
            MAKE_PROP(Int,      Integer,    int,            "libtorrent.active_tracker_limit", "active_tracker_limit"),
            MAKE_PROP(Int,      Integer,    int,            "libtorrent.allowed_fast_set_size", "allowed_fast_set_size"),
            MAKE_PROP(Bool,     Bool,       bool,           "libtorrent.allow_multiple_connections_per_ip", "allow_multiple_connections_per_ip"),
            MAKE_PROP(Bool,     Bool,       bool,           "libtorrent.announce_to_all_tiers", "announce_to_all_tiers"),
            MAKE_PROP(Bool,     Bool,       bool,           "libtorrent.announce_to_all_trackers", "announce_to_all_trackers"),
            MAKE_PROP(Bool,     Bool,       bool,           "libtorrent.anonymous_mode", "anonymous_mode"),
            MAKE_PROP(Int,      Integer,    int,            "libtorrent.auto_manage_interval", "auto_manage_interval"),
            MAKE_PROP(Bool,     Bool,       bool,           "libtorrent.auto_manage_prefer_seeds", "auto_manage_prefer_seeds"),
            MAKE_PROP(Int,      Integer,    int,            "libtorrent.auto_scrape_interval", "auto_scrape_interval"),
            MAKE_PROP(Int,      Integer,    int,            "libtorrent.auto_scrape_min_interval", "auto_scrape_min_interval"),
            MAKE_PROP(Int,      Integer,    int,            "libtorrent.checking_mem_usage", "checking_mem_usage"),
            MAKE_PROP(Int,      Integer,    int,            "libtorrent.choking_algorithm", "choking_algorithm"),
            MAKE_PROP(Int,      Integer,    int,            "libtorrent.connection_speed", "connection_speed"),
            MAKE_PROP(Int,      Integer,    int,            "libtorrent.disk_write_mode", "disk_write_mode"),
            MAKE_PROP(Bool,     Bool,       bool,           "libtorrent.dont_count_slow_torrents", "dont_count_slow_torrents"),
            MAKE_PROP(Int,      Integer,    int,            "libtorrent.file_pool_size", "file_pool_size"),
            MAKE_PROP(Int,      Integer,    int,            "libtorrent.hashing_threads", "hashing_threads"),
            MAKE_PROP(Int,      Integer,    int,            "libtorrent.inactive_down_rate", "inactive_down_rate"),
            MAKE_PROP(Int,      Integer,    int,            "libtorrent.inactive_up_rate", "inactive_up_rate"),
            MAKE_PROP(Int,      Integer,    int,            "libtorrent.inactivity_timeout", "inactivity_timeout"),
            MAKE_PROP(Bool,     Bool,       bool,           "libtorrent.incoming_starts_queued_torrents", "incoming_starts_queued_torrents"),
            MAKE_PROP(Int,      Integer,    int,            "libtorrent.initial_picker_threshold", "initial_picker_threshold"),
            MAKE_PROP(Int,      Integer,    int,            "libtorrent.listen_queue_size", "listen_queue_size"),
            MAKE_PROP(Int,      Integer,    int,            "libtorrent.max_allowed_in_request_queue", "max_allowed_in_request_queue"),
            MAKE_PROP(Int,      Integer,    int,            "libtorrent.max_failcount", "max_failcount"),
            MAKE_PROP(Int,      Integer,    int,            "libtorrent.max_out_request_queue", "max_out_request_queue"),
            MAKE_PROP(Int,      Integer,    int,            "libtorrent.max_peer_recv_buffer_size", "max_peer_recv_buffer_size"),
            MAKE_PROP(Int,      Integer,    int,            "libtorrent.max_queued_disk_bytes", "max_queued_disk_bytes"),
            MAKE_PROP(Int,      Integer,    int,            "libtorrent.max_rejects", "max_rejects"),
            MAKE_PROP(Int,      Integer,    int,            "libtorrent.min_reconnect_time", "min_reconnect_time"),
            MAKE_PROP(Int,      Integer,    int,            "libtorrent.mixed_mode_algorithm", "mixed_mode_algorithm"),
            MAKE_PROP(Int,      Integer,    int,            "libtorrent.mmap_file_size_cutoff", "mmap_file_size_cutoff"),
            MAKE_PROP(Bool,     Bool,       bool,           "libtorrent.no_atime_storage", "no_atime_storage"),
            MAKE_PROP(Int,      Integer,    int,            "libtorrent.peer_timeout", "peer_timeout"),
            MAKE_PROP(Int,      Integer,    int,            "libtorrent.peer_turnover", "peer_turnover"),
            MAKE_PROP(Int,      Integer,    int,            "libtorrent.peer_turnover_cutoff", "peer_turnover_cutoff"),
            MAKE_PROP(Int,      Integer,    int,            "libtorrent.peer_turnover_interval", "peer_turnover_interval"),
            MAKE_PROP(Int,      Integer,    int,            "libtorrent.predictive_piece_announce", "predictive_piece_announce"),
            MAKE_PROP(Int,      Integer,    int,            "libtorrent.rate_choker_initial_threshold", "rate_choker_initial_threshold"),
            MAKE_PROP(Int,      Integer,    int,            "libtorrent.request_timeout", "request_timeout"),
            MAKE_PROP(Int,      Integer,    int,            "libtorrent.seed_choking_algorithm", "seed_choking_algorithm"),
            MAKE_PROP(Int,      Integer,    int,            "libtorrent.seed_time_ratio_limit", "seed_time_ratio_limit"),
            MAKE_PROP(Int,      Integer,    int,            "libtorrent.send_buffer_low_watermark", "send_buffer_low_watermark"),
            MAKE_PROP(Int,      Integer,    int,            "libtorrent.send_buffer_watermark", "send_buffer_watermark"),
            MAKE_PROP(Int,      Integer,    int,            "libtorrent.send_buffer_watermark_factor", "send_buffer_watermark_factor"),
            MAKE_PROP(Int,      Integer,    int,            "libtorrent.send_not_sent_low_watermark", "send_not_sent_low_watermark"),
            MAKE_PROP(Int,      Integer,    int,            "libtorrent.share_ratio_limit", "share_ratio_limit"),
            MAKE_PROP(Int,      Integer,    int,            "libtorrent.stop_tracker_timeout", "stop_tracker_timeout"),
            MAKE_PROP(Bool,     Bool,       bool,           "libtorrent.strict_end_game_mode", "strict_end_game_mode"),
            MAKE_PROP(Int,      Integer,    int,            "libtorrent.suggest_mode", "suggest_mode"),
            MAKE_PROP(Int,      Integer,    int,            "libtorrent.torrent_connect_boost", "torrent_connect_boost"),
            MAKE_PROP(Int,      Integer,    int,            "libtorrent.unchoke_slots_limit", "unchoke_slots_limit"),
            MAKE_PROP(Bool,     Bool,       bool,           "libtorrent.use_parole_mode", "use_parole_mode"),
            MAKE_PROP(Int,      Integer,    int,            "libtorrent.whole_pieces_threshold", "whole_pieces_threshold")
        }
    },
    {
        "PicoTorrent",
        {
            MAKE_PROP(Int,  Integer, int,  "save_resume_data_interval",   "save_resume_data_interval"),
            MAKE_PROP(Int,  Integer, int,  "ui.torrent_overview.columns", "torrent_overview_columns"),
            MAKE_PROP(Bool, Bool,    bool, "ui.torrent_overview.show_piece_progress", "torrent_overview_show_piece_progress")
        }
    }
};

PreferencesAdvancedPage::PreferencesAdvancedPage(wxWindow* parent, std::shared_ptr<pt::Core::Configuration> cfg)
    : wxPanel(parent),
    m_cfg(cfg)
{
    m_grid = new wxPropertyGridManager(
        this,
        wxID_ANY,
        wxDefaultPosition,
        wxDefaultSize,
        wxPG_BOLD_MODIFIED | wxPG_SPLITTER_AUTO_CENTER | wxPG_DESCRIPTION | wxPGMAN_DEFAULT_STYLE);

    m_page = m_grid->AddPage();

    for (auto& [category, props] : properties)
    {
        m_page->Append(new wxPropertyCategory(category));

        for (auto& [key, prop] : props)
        {
            auto p = prop.ctor();

            // Set prop value
            prop.get(
                m_cfg.get(),
                p);

            p->SetHelpString(i18n("advanced_desc_" + key));
            m_page->Append(p);
        }
    }

    // Checkboxes instead of the untranslated "True"/"False" texts.
    m_page->SetPropertyAttributeAll(wxPG_BOOL_USE_CHECKBOX, true);

    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(m_grid, 1, wxEXPAND | wxALL);

    this->SetSizerAndFit(sizer);
}

void PreferencesAdvancedPage::Save()
{
    for (auto& [cat, props] : properties)
    {
        for (auto& [key, prop] : props)
        {
            prop.set(
                m_cfg.get(),
                m_page->GetProperty(key));
        }
    }
}
