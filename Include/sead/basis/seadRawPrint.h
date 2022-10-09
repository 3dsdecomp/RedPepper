#pragma once

#include <stdarg.h>

#include "sead/basis/seadTypes.h"

#ifdef SEAD_DEBUG
#define SEAD_ASSERT_MSG(condition, message, ...)                                      \
    do {                                                                              \
        if (!(condition))                                                             \
            sead::system::HaltWithDetail(__FILE__, __LINE__, message, ##__VA_ARGS__); \
    } while (0)
#define SEAD_ASSERT(condition)                                                    \
    do {                                                                          \
        if (!(condition))                                                         \
            sead::system::HaltWithDetailNoFormat(__FILE__, __LINE__, #condition); \
    } while (0)
#define SEAD_WARN(message, ...)                                            \
    do                                                                     \
        sead::system::Warning(__FILE__, __LINE__, message, ##__VA_ARGS__); \
    while (0)
#define SEAD_DEBUG_PRINT(format, ...)               \
    do                                              \
        sead::system::Print(format, ##__VA_ARGS__); \
    while (0)
#else
#define SEAD_ASSERT_MSG(condition, message, ...)                       \
    do {                                                               \
        if (false) {                                                   \
            static_cast<void>(condition);                              \
            sead::system::detail::CheckFormat(message, ##__VA_ARGS__); \
        }                                                              \
    } while (0)
#define SEAD_ASSERT(condition)            \
    do {                                  \
        if (false)                        \
            static_cast<void>(condition); \
    } while (0)
#define SEAD_WARN(message, ...)                                        \
    do {                                                               \
        if (false)                                                     \
            sead::system::detail::CheckFormat(message, ##__VA_ARGS__); \
    } while (0)
#define SEAD_DEBUG_PRINT(format, ...)                                 \
    do {                                                              \
        if (false)                                                    \
            sead::system::detail::CheckFormat(format, ##__VA_ARGS__); \
    } while (0)
#endif

namespace sead {
namespace system {
    namespace detail {
        // Dummy function whose only purpose is to trigger a format string check.
        inline void
        CheckFormat(const char*, ...)
        {
        }
    } // namespace detail

    void Halt();
    void HaltWithDetail(const char* file, int line, const char* msg, ...);
    void HaltWithDetailNoFormat(const char* file, int line, const char* msg);
    void DebugBreak();

    void Print(const char* format, ...);
    void PrintV(const char* format, va_list);
    void PrintString(const char* format, s32);

    void Warning(const char* file, int line, const char* msg, ...);
    void SetWarningEnable(bool enable);
} // namespace system
} // namespace sead
