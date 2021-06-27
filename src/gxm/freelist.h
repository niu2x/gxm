#ifndef GXM_FREELIST_H
#define GXM_FREELIST_H

namespace gxm {

using rid = uint16_t;

constexpr rid nil_id = 0xFFFF;

template <class T>
struct slot {
    T   data;
    rid next;
};

template <class T, uint64_t N>
class freelist {
public:
    freelist() {
        next_ = 0;

        slot<T> *ptr = slots_;
        for (uint64_t i = 0; i < N - 1; i++, ptr++) {
            ptr->next = i + 1;
        }
        ptr->next = nil_id;
    }

    rid alloc() {
        if (next_ == nil_id)
            return nil_id;
        auto result = next_;

        next_ = slots_[result].next;
        return result;
    }

    void free(rid p_rid) {
        GXM_ASSERT(p_rid != nil_id, "p_rid is nil_id");
        slots_[p_rid].next = next_;

        next_ = p_rid;
    }

    T *get(rid p_rid) {
        GXM_ASSERT(p_rid != nil_id, "p_rid is nil_id");
        return &(slots_[p_rid].data);
    }

private:
    slot<T> slots_[N];
    rid     next_;
};

} // namespace gxm

#endif