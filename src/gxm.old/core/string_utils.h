#ifndef GXM_BASE_STRING_UTILS_H
#define GXM_BASE_STRING_UTILS_H

#include <string>
#include <type_traits>

#include <gxm/core/to_string.h>

namespace gxm::core {

struct string_utils {
    template <class First, class... Others>
    static std::string concat(First &&first, Others &&... others) {
        std::string result = to_string<typename std::decay<First>::type>::cvt(
            std::forward<First>(first));
        if constexpr (sizeof...(others) > 0) {
            result += concat(std::forward<Others>(others)...);
        }
        return result;
    }

    template <class First, class... Others>
    static std::string concat_with(
        const std::string &seq,
        First &&           first,
        Others &&... others) {
        std::string result = to_string<typename std::decay<First>::type>::cvt(
            std::forward<First>(first));
        if constexpr (sizeof...(others) > 0) {
            result += seq + concat_with(seq, std::forward<Others>(others)...);
        }
        return result;
    }
};

} // namespace gxm::core

#endif