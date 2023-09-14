#ifndef __NexCore_Core_Log_H__
#define __NexCore_Core_Log_H__

#ifdef NEXCORE_DEBINFO
#include <spdlog/spdlog.h>
#define log_info(...) spdlog::info(__VA_ARGS__)
#define log_warn(...) spdlog::warn(__VA_ARGS__)
#define log_crit(...) spdlog::critical(__VA_ARGS__)
#else
#define log_info(...)
#define log_warn(...)
#define log_crit(...)
#endif

#endif // __NexCore_Core_Log_H__