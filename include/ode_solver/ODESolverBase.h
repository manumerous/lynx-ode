#pragma once

#include <vector>
#include "system_dynamics/SystemFlowMapBase.h"

namespace lynx_ode {

class ODESolverBase {
 public:
  virtual vector_array_t integrate(const SystemFlowMapBase* functionPtr, const vector_t& initialState, size_t n_steps, double delta_t) = 0;
};

}  // namespace lynx_ode