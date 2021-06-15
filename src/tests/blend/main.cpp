#include <iostream>

#include <gxm/driver/gpu/blend.h>
#include <gxm/base/log.h>

using namespace gxm::driver::gpu;

int main() {
    blend_t bl = 0;
    GXM_LOG_D(std::string("valid: ") + std::to_string(blend_utils::valid(bl)));

    blend_utils::set_valid(bl, true);
    GXM_LOG_D(std::string("valid: ") + std::to_string(blend_utils::valid(bl)));

    blend_utils::set_valid(bl, false);
    GXM_LOG_D(std::string("valid: ") + std::to_string(blend_utils::valid(bl)));

    GXM_LOG_D(
        std::string("enable: ") + std::to_string(blend_utils::enable(bl)));

    blend_utils::set_enable(bl, true);
    GXM_LOG_D(
        std::string("enable: ") + std::to_string(blend_utils::enable(bl)));

    blend_utils::set_enable(bl, false);
    GXM_LOG_D(
        std::string("enable: ") + std::to_string(blend_utils::enable(bl)));

    GXM_LOG_D(
        std::string("src_factor: ") +
        std::to_string((int)blend_utils::src_factor(bl)));

    blend_utils::set_src_factor(bl, blend_factor_t::src_alpha);
    GXM_LOG_D(
        std::string("src_factor: ") +
        std::to_string((int)blend_utils::src_factor(bl)));

    blend_utils::set_src_factor(bl, blend_factor_t::one);
    GXM_LOG_D(
        std::string("src_factor: ") +
        std::to_string((int)blend_utils::src_factor(bl)));

    GXM_LOG_D(
        std::string("dst_factor: ") +
        std::to_string((int)blend_utils::dst_factor(bl)));

    blend_utils::set_dst_factor(bl, blend_factor_t::one_minus_src_alpha);
    GXM_LOG_D(
        std::string("dst_factor: ") +
        std::to_string((int)blend_utils::dst_factor(bl)));

    blend_utils::set_dst_factor(bl, blend_factor_t::zero);
    GXM_LOG_D(
        std::string("dst_factor: ") +
        std::to_string((int)blend_utils::dst_factor(bl)));

    GXM_LOG_D(std::string("op: ") + std::to_string((int)blend_utils::op(bl)));

    blend_utils::set_op(bl, blend_op_t::sub);
    GXM_LOG_D(std::string("op: ") + std::to_string((int)blend_utils::op(bl)));

    blend_utils::set_op(bl, blend_op_t::min);
    GXM_LOG_D(std::string("op: ") + std::to_string((int)blend_utils::op(bl)));

    GXM_LOG_D(std::string("valid: ") + std::to_string(blend_utils::valid(bl)));
    GXM_LOG_D(
        std::string("enable: ") + std::to_string(blend_utils::enable(bl)));
    GXM_LOG_D(
        std::string("src_factor: ") +
        std::to_string((int)blend_utils::src_factor(bl)));
    GXM_LOG_D(
        std::string("dst_factor: ") +
        std::to_string((int)blend_utils::dst_factor(bl)));
    GXM_LOG_D(std::string("op: ") + std::to_string((int)blend_utils::op(bl)));

    return 0;
}