#pragma once

#include <vector>
#include "system_dynamics/SystemFlowMapBase.h"

namespace lynx_ode {

class ODEIntegratorBase {
 public:
  // Implementation for default inegrator with fixed time step delta_t = integrationHorizonTime / n_steps
  virtual vector_array_t integrate(const SystemFlowMapBase* flowMapPtr, const vector_t& initialState, size_t n_steps,
                                   scalar_t integrationHorizonTime);

 private:
  virtual vector_t integrationStep(const SystemFlowMapBase* flowMapPtr, const vector_t& initialState, scalar_t delta_t) = 0;
};

}  // namespace lynx_ode