/**
 * @defgroup   INITER initer
 *
 * @brief      This file implements initer.
 *
 * @author     Niu2x
 * @date       2021
 */

#ifndef GXM_INITER_H
#define GXM_INITER_H

/**
 * @addtogroup BASE
 * @{
 *
 * @addtogroup INITER
 * @{
 */

/**
 * @brief      auto execute a function when app startup.
 *
 * @param      f     function
 */
#define GXM_INITER(f)                                                \
    struct _initer {                                                 \
        _initer() {                                                  \
            f();                                                     \
        }                                                            \
    }

/**
 * @}
 *
 * @}
 */

#endif