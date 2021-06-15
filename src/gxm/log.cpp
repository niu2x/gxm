#include "log.h"
#include "macro.h"

namespace gxm {

log::log()
    : level_(level::trace) {}

log::~log() {}

// void log::set_log_file(const char *pathname) {
//     unused(pathname, pathname, pathname);
// }

void log::set_level(level p_level) {
    level_ = p_level;
}

namespace {

// clang-format off
const char *level_colors[] = { 
    "\x1b[94m", 
    "\x1b[36m", 
    "\x1b[33m", 
    "\x1b[31m", 
    "\x1b[35m"
};

const char *level_names[] = {
    "trace",
    "debug",
    "warning",
    "error",
    "fatal",
};
// clang-format on

} // namespace

void log::write(level p_level, const char *msg) {
    if (p_level >= level_) {
        int   lvl = int(p_level);
        auto *fmt = "\x1b[0m \x1b[90m%s[%s] %s\x1b[0m\n";
        fprintf(stderr, fmt, level_colors[lvl], level_names[lvl], msg);
    }
}

} // namespace gxm
