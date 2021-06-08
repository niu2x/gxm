#ifndef GXM_ASSERT_H
#define GXM_ASSERT_H

#include <gxm/base/log.h>
#include <gxm/throw.h>

#define GXM_ASSERT_W(cond, message)                                  \
    do {                                                             \
        if (!(cond)) {                                               \
            gxm::base::log::w(message);                              \
        }                                                            \
    } while (false);

#define GXM_ASSERT_F(cond, message)                                  \
    do {                                                             \
        if (!(cond)) {                                               \
            gxm::base::log::f(message);                              \
            GXM_THROW(message);                                      \
        }                                                            \
    } while (false);

#endif