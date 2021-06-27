#ifndef GXM_LOG_H
#define GXM_LOG_H

#include <gxm/macro.h>

namespace gxm {

struct log {
    enum class level {
        trace,
        debug,
        warning,
        error,
        fatal,
    };

    static void write(
        level       p_level,
        const char *filename,
        int         line,
        const char *message,
        ...);
};

} // namespace gxm

#define GXM_LOG_T(message, ...) GXM_LOG_WRITE(trace, message, ##__VA_ARGS__)
#define GXM_LOG_D(message, ...) GXM_LOG_WRITE(debug, message, ##__VA_ARGS__)
#define GXM_LOG_W(message, ...) GXM_LOG_WRITE(warning, message, ##__VA_ARGS__)
#define GXM_LOG_E(message, ...) GXM_LOG_WRITE(error, message, ##__VA_ARGS__)
#define GXM_LOG_F(message, ...) GXM_LOG_WRITE(fatal, message, ##__VA_ARGS__)

#define GXM_LOG_WRITE(p_level, message, ...)                                   \
    gxm::log::write(                                                           \
        gxm::log::level::p_level,                                              \
        __FILE__,                                                              \
        __LINE__,                                                              \
        (message),                                                             \
        ##__VA_ARGS__)

#endif