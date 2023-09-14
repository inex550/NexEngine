#ifndef __NexCore_Core_Core_H__
#define __NexCore_Core_Core_H__

#include <NexCore/Core/Log.h>

#ifdef NEXCORE_DEBINFO
    #define NEXCORE_ENABLE_ASSERT
#endif

#ifdef NEXCORE_ENABLE_ASSERT
#include <cassert>
#define NEX_ASSERT(cond, ...) { if (!(cond)) log_crit("Assertion failed: {0}", __VA_ARGS__); assert(cond); }
#else
#define NEX_ASSERT(cond, ...)
#endif

#endif // __NexCore_Core_Core_H__