#pragma once

#include <common/Types.h>

namespace lynx_ode {

class SystemFlowMapBase {
 public:
  virtual matrix_t getLinearApproximation(const vector_t& state) const = 0;
};

}  // namespace lynx_ode
