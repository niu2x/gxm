#ifndef GXM_CORE_RID_H
#define GXM_CORE_RID_H

#include <unordered_map>

#include <boost/noncopyable.hpp>

namespace gxm::core {

// class rid {
// public:

// 	template<class T>
// 	class list: private std::vector<T> {

// 	};

// };

using rid = uint64_t;

struct rid_factory {
    static rid next_rid() {
        return ++next_;
    }

private:
    static rid next_;
};

template <class T>
class res_owner : private boost::noncopyable {
public:
    res_owner() {}
    ~res_owner() {}

    rid new_res() {
        rid new_rid = rid_factory::next_rid();
        res_dict_.emplace(new_rid, T());
        return new_rid;
    }

    void delete_res(const rid &p_rid) {
        res_dict_.erase(p_rid);
    }

    T *get_res(const rid &p_rid) {
        auto iter = res_dict_.find(p_rid);
        if (iter != res_dict_.end())
            return &(iter->second);
        return nullptr;
    }

private:
    std::unordered_map<rid, T> res_dict_;
};

} // namespace gxm::core

#endif