#ifndef GXM_LOG_H
#define GXM_LOG_H

#include <string>

#include <boost/noncopyable.hpp>

namespace gxm {

class log : boost::noncopyable {

public:
    enum class level {
        trace,
        debug,
        warning,
        error,
        fatal,
    };

    log();
    ~log();

    // void set_log_file(const char *pathname);

    void set_level(level p_level);

    void t(const char *message) {
        write(level::trace, message);
    }
    void d(const char *message) {
        write(level::debug, message);
    }
    void w(const char *message) {
        write(level::warning, message);
    }
    void e(const char *message) {
        write(level::error, message);
    }
    void f(const char *message) {
        write(level::fatal, message);
    }

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
    level level_;

    void write(level p_level, const char *message);
};

} // namespace gxm

#endif