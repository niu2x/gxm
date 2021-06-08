#ifndef GXM_SPTR_H
#define GXM_SPTR_H

#include <memory>

namespace gxm {

template <class T>
using sptr = std::shared_ptr<T>;

} // namespace gxm

#endif
