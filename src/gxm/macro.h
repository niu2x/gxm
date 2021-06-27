#ifndef GXM_MACRO_H
#define GXM_MACRO_H

#include <cstdint>
#include <exception>
#include <cstdio>

namespace gxm {

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

} // namespace gxm

/**
 * @brief      throw a exception
 *
 * @param      message  The exception's message
 *
 */
#define GXM_THROW(message) throw gxm::exception((message), __FILE__, __LINE__)

#define GXM_UNUSED(x) (void)(x)

#define GXM_ASSERT(cond, message)                                              \
    if (!(cond)) {                                                             \
        GXM_THROW(message);                                                    \
    }

// #define GXM_API __attribute__((__visibility__("default")))

#endif