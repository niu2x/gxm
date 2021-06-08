#ifndef GXM_THROW_H
#define GXM_THROW_H

#include <gxm/base/exception.h>

#define GXM_THROW(message)                                           \
    throw gxm::base::exception((message), __FILE__, __LINE__)

#endif