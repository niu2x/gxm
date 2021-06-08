#ifndef GXM_UPTR_H
#define GXM_UPTR_H

#include <memory>

namespace gxm {

template <class T>
using uptr = std::unique_ptr<T>;

} // namespace gxm

#endif
