#ifndef GXM_CORE_FREELIST_H
#define GXM_CORE_FREELIST_H

#include <type_traits>
#include <cstdint>
#include <cstddef>

namespace gxm::core {

template <class T, int block_size, class Enable = void>
class freelist {
private:
    freelist();
    ~freelist();
};

template <class T, int block_size>
class freelist<T, block_size, std::enable_if_t<std::is_pod_v<T>, void>> {
public:
    using index_t = size_t;
    using elem_t  = union {
        index_t next;
        T       data;
    };

    struct block {
        elem_t elems[block_size];
        block *next;
    };

private:
    block   first_block_;
    index_t next_;
};

} // namespace gxm::core

#endif