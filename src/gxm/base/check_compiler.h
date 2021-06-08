/**
 * @defgroup   CHECK_COMPILER check compiler
 *
 * @brief      This file implements check compiler.
 *
 * @author     Niu2x
 * @date       2021
 */

#ifndef GXM_CHECK_COMPILER_H
#define GXM_CHECK_COMPILER_H

/**
 * @addtogroup BASE
 * @{
 *
 * @addtogroup CHECK_COMPILER
 * @{
 */

#define GXM_COMPILER_UNKNOWN 0
#define GXM_COMPILER_GNU     1
#define GXM_COMPILER_CLANG   2
#define GXM_COMPILER_MSC     3

#if defined(__clang__)
#define GXM_COMPILER GXM_COMPILER_CLANG

#elif defined(__GNUC__) || defined(__GNUG__)
#define GXM_COMPILER GXM_COMPILER_GNU

#elif defined(_MSC_VER)
#define GXM_COMPILER GXM_COMPILER_MSC

#else
/**
 * GXM_COMPILER is defined to something(eg: GXM_COMPILER_GNU) at
 * compile time.
 */
#define GXM_COMPILER GXM_COMPILER_UNKNOWN

#endif

/**
 * @}
 *
 * @}
 */

#endif