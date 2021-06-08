#ifndef GXM_UNUSED_H
#define GXM_UNUSED_H

#define GXM_UNUSED(expr) (void)(expr);

namespace gxm {

template <class T>
inline void unused(const T &t) {
    GXM_UNUSED(t);
}

} // namespace gxm

#endif