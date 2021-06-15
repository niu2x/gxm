#include <gxm/base/log.h>

#include <boost/log/core.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/trivial.hpp>

#include <gxm/base/unused.h>

namespace bl = boost::log;

namespace gxm {

log log::default_;

void log::set_log_file(const char *pathname) {
    unused(pathname);
}

void log::set_log_level(level p_log_level) {
    decltype(bl::trivial::fatal) bl_level;

    switch (p_log_level) {
        case level::trace: {
            bl_level = bl::trivial::trace;
            break;
        }
        case level::debug: {
            bl_level = bl::trivial::debug;
            break;
        }
        case level::warning: {
            bl_level = bl::trivial::warning;
            break;
        }
        case level::error: {
            bl_level = bl::trivial::error;
            break;
        }
        case level::fatal: {
            bl_level = bl::trivial::fatal;
            break;
        }
    }

    bl::core::get()->set_filter(bl::trivial::severity >= bl_level);
}

void log::t(const char *message) {
    BOOST_LOG_TRIVIAL(trace) << message;
}
void log::d(const char *message) {
    BOOST_LOG_TRIVIAL(debug) << message;
}
void log::w(const char *message) {
    BOOST_LOG_TRIVIAL(warning) << message;
}
void log::e(const char *message) {
    BOOST_LOG_TRIVIAL(error) << message;
}
void log::f(const char *message) {
    BOOST_LOG_TRIVIAL(fatal) << message;
}

} // namespace gxm
