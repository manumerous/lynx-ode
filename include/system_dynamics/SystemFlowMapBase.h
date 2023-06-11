#pragma once

#include <common/Types.h>

namespace turbo_lynx_ode {

class SystemFlowMapBase {
 public:
  virtual matrix_t getLinearApproximation(const vector_t& state) const = 0;
};

}  // namespace turbo_lynx_ode
