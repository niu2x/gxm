/**
 * @defgroup   VERSION version
 *
 * @brief      This file implements version.
 *
 * @author     Niu2x
 * @date       2021
 */

#ifndef GXM_VERSION_H
#define GXM_VERSION_H

#include <cstdint>

namespace gxm {

/**
 * @addtogroup BASE
 * @{
 *
 * @addtogroup VERSION
 * @{
 */

/**
 * @brief      gxm's version info
 */
struct version {

    /**
     * @brief      get gxm's major version code.
     *
     * @return     gxm's major version code.
     */
    static uint32_t major() noexcept;

    /**
     * @brief      get gxm's minor version code.
     *
     * @return     gxm's minor version code.
     */
    static uint32_t minor() noexcept;

    /**
     * @brief      get gxm's patch version code.
     *
     * @return     gxm's patch version code.
     */
    static uint32_t patch() noexcept;

    /**
     * @brief      get gxm's tweak version code.
     *
     * @return     gxm's tweak version code.
     */
    static uint32_t tweak() noexcept;

    /**
     * @brief      get gxm's version str.
     *
     * @return     gxm's version str.
     */
    static const char *c_str() noexcept;
};

/**
 * @}
 *
 * @}
 */

} // namespace gxm

#endif