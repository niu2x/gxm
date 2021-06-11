#include <gxm/driver/gpu/blend.h>

namespace gxm::driver::gpu {

blend blend::zero(
    blend::factor_t::zero,
    blend::factor_t::one,
    blend::op_t::add);

blend blend::one(
    blend::factor_t::one,
    blend::factor_t::zero,
    blend::op_t::add);

blend blend::normal(
    blend::factor_t::src_alpha,
    blend::factor_t::one_minus_src_alpha,
    blend::op_t::add);

} // namespace gxm::driver::gpu