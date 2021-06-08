#ifndef GXM_CORE_TO_STRING_H
#define GXM_CORE_TO_STRING_H

#include <string>

namespace gxm::core {

template <class T>
struct to_string {};

template <>
struct to_string<const char *> {
    static std::string cvt(const char *sz) {
        return std::string(sz);
    }
};

template <>
struct to_string<char> {
    static std::string cvt(char c) {
        return std::string("") + c;
    }
};

template <int N>
struct to_string<char[N]> {
    static std::string cvt(const char sz[N]) {
        return std::string(sz);
    }
};

template <>
struct to_string<int> {
    static std::string cvt(int n) {
        return std::to_string(n);
    }
};

template <>
struct to_string<std::string> {
    static std::string cvt(const std::string &sz) {
        return sz;
    }

    static std::string cvt(std::string &&sz) {
        return sz;
    }
};

} // namespace gxm::core

#endif