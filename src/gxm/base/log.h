/**
 * @defgroup   LOG log
 *
 * @brief      This file implements log.
 *
 * @author     Niu2x
 * @date       2021
 */

#ifndef GXM_LOG_H
#define GXM_LOG_H

#include <string>
#include <type_traits>

#define GXM_LOG_T(message) gxm::log::get().t((message))
#define GXM_LOG_D(message) gxm::log::get().d((message))
#define GXM_LOG_W(message) gxm::log::get().w((message))
#define GXM_LOG_E(message) gxm::log::get().e((message))
#define GXM_LOG_F(message) gxm::log::get().f((message))

namespace gxm {

/**
 * @addtogroup BASE
 * @{
 *
 * @addtogroup LOG
 * @{
 */

/**
 * @brief      log class
 */
struct log {
    /**
     * @brief      log's level
     */
    enum class level {
        fatal,
        error,
        warning,
        debug,
        trace,
    };

    /**
     * @brief      get global default log instance.
     *
     * @return     a log instance.
     */
    static log &get() {
        return default_;
    }

    /**
     * @brief      write log in a log file.
     *
     * @param[in]  pathname  The log file's pathname.
     */
    void set_log_file(const char *pathname);

    /**
     * @brief      set log's level.
     *
     * @param[in]  p_log_level  The log level
     */
    void set_log_level(level p_log_level);

    void t(const char *message);
    void d(const char *message);
    void w(const char *message);
    void e(const char *message);
    void f(const char *message);

    void t(const std::string &message) {
        t(message.c_str());
    }
    void d(const std::string &message) {
        d(message.c_str());
    }
    void w(const std::string &message) {
        w(message.c_str());
    }
    void e(const std::string &message) {
        e(message.c_str());
    }
    void f(const std::string &message) {
        f(message.c_str());
    }

private:
    static log default_;
};

/**
 * @}
 *
 * @}
 */

} // namespace gxm

#endif