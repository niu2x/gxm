#ifndef GXM_ASSERT_H
#define GXM_ASSERT_H

#include <gxm/base/log.h>
#include <gxm/base/exception.h>

#define GXM_ASSERT_W(cond, message)                                  \
    do {                                                             \
        if (!(cond)) {                                               \
            GXM_LOG_W(message);                                      \
        }                                                            \
    } while (false);

#define GXM_ASSERT_F(cond, message)                                  \
    do {                                                             \
        if (!(cond)) {                                               \
            GXM_LOG_F(message);                                      \
            GXM_THROW(message);                                      \
        }                                                            \
    } while (false);

#endif