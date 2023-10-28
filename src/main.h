#pragma once

#include <vector>
#include <string>

namespace Main
{

const std::string file_path_prefix{"../include/dpp/"};

/**
 * @brief All folders that the program should ignore when generating Unreal functions.
 */
std::vector<std::string> folders_to_ignore = { "coro",
					       "isa",
					       "nlohmann"
					       };

/**
 * @brief All files that the program should ignore when generating Unreal functions.
 */
std::vector<std::string> files_to_ignore = { "cache.h",
					     "collector.h",
					     "cluster_coro_calls.h",
					     "cluster_sync_calls.h",
					     "commandhandler.h",
					     "coro.h",
					     "discordevents.h",
					     "discordvoiceclient.h",
					     "dns.h",
					     "dpp.h",
					     "event.h",
					     "event_router.h",
					     "exception.h",
					     "export.h",
					     "httpsclient.h",
					     "isa_detection.h",
					     "json.h",
					     "json_fwd.h",
					     "json_interface.h",
					     "managed.h",
					     "once.h",
					     "queues.h",
					     "restrequest.h",
					     "restresults.h",
					     "socket.h",
					     "stringops.h",
					     "sync.h",
					     "sysdep.h",
					     "timed_listener.h", /* This is because Unreal Engine has timers. */
					     "timer.h", /* This is because Unreal Engine has timers. */
					     "utility.h",
					     "version.h",
					     "win32_safe_warnings.h",
					     "wsclient.h"
					     };

};
