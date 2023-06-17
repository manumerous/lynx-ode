#include "ode_integrator/ODEIntegratorBase.h"

namespace lynx_ode {

vector_array_t ODEIntegratorBase::integrate(const SystemFlowMapBase* flowMapPtr, const vector_t& initialState, size_t n_steps,
                                            scalar_t integrationHorizonTime) {
  scalar_t delta_t = integrationHorizonTime / n_steps;
  vector_array_t stateTrajectory;
  stateTrajectory.reserve(n_steps + 1);
  stateTrajectory.emplace_back(initialState);

  for (int i = 0; i < n_steps; i++) {
    stateTrajectory.emplace_back(integrationStep(flowMapPtr, stateTrajectory[i], delta_t));
  }

  return stateTrajectory;
}

}  // namespace lynx_ode