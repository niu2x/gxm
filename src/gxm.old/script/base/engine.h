#ifndef GXM_SCRIPT_BASE_ENGINE_H
#define GXM_SCRIPT_BASE_ENGINE_H

#include <gxm/common.h>

namespace gxm::script::base {

class engine : private boost::noncopyable {
public:
    virtual ~engine() {}

    virtual bool execute_file(const char *) = 0;
    virtual bool execute(const char *)      = 0;
};

} // namespace gxm::script::base

#endif