#ifndef GXM_MACRO_H
#define GXM_MACRO_H

#include <cstdint>

namespace gxm {

template <class T>
uint8_t unused_one(const T &t) {
    (void)(t);
    return 0;
}

template <class... T>
void unused(const T &... t) {
    auto x = {unused_one(t)...};
    unused_one(x);
}

} // namespace gxm

#endif