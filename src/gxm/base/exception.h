/**
 * @defgroup   EXCEPTION exception
 *
 * @brief      This file implements exception.
 *
 * @author     Niu2x
 * @date       2021
 */

#ifndef GXM_EXCEPTION_H
#define GXM_EXCEPTION_H

#include <exception>
#include <cstdint>
#include <cstdio>

namespace gxm {

/**
 * @addtogroup BASE
 * @{
 *
 * @addtogroup EXCEPTION
 * @{
 */

/**
 * @brief      Exception for signaling  errors.
 */
class exception : public std::exception {
public:
    /**
     * @brief      Constructs a new exception.
     *
     * @param[in]  msg   The message
     * @param[in]  file  The file
     * @param[in]  line  The line
     */
    exception(const char *msg, const char *file, uint32_t line) {
        const char *fmt = "%s\nat: %s line: %d";
        snprintf(msg_, buffer_size, fmt, msg, file, line);
    }

    virtual ~exception() {}

    /**
     * @brief      get exception's description.
     *
     * @return     description of exception.
     */
    virtual const char *what() const noexcept override {
        return msg_;
    }

private:
    enum { buffer_size = 2048 };
    char msg_[buffer_size];
};

/**
 * @brief      throw a exception
 *
 * @param      message  The exception's message
 *
 */
#define GXM_THROW(message)                                           \
    throw gxm::exception((message), __FILE__, __LINE__)

/**
 * @}
 *
 * @}
 */

} // namespace gxm

#endif
