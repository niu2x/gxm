/**
 * @defgroup   UNUSED unused
 *
 * @brief      This file implements unused.
 *
 * @author     Niu2x
 * @date       2021
 */

#ifndef GXM_UNUSED_H
#define GXM_UNUSED_H

#define GXM_UNUSED(expr) (void)(expr);

namespace gxm {

/**
 * @addtogroup BASE
 * @{
 *
 * @addtogroup UNUSED
 * @{
 */

template <class T>
/**
 * @brief      dismiss warning of unused param.
 *
 * @param[in]  t     unused param.
 */
inline void unused(const T &t) {
  GXM_UNUSED(t);
}

/**
 * @}
 *
 * @}
 */

} // namespace gxm

#endif