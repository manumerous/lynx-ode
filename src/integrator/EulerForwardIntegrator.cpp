#include "ode_integrator/EulerForwardIntegrator.h"

namespace lynx_ode {

vector_array_t EulerForwardIntegrator::integrate(const SystemFlowMapBase* flowMapPtr, const vector_t& initialState, size_t n_steps,
                                                 scalar_t delta_t) {
  vector_array_t stateTrajectory;
  stateTrajectory.reserve(n_steps + 1);
  stateTrajectory.emplace_back(initialState);

  for (int i = 0; i < n_steps; i++) {
    const vector_t& currentState = stateTrajectory[i];
    vector_t nextValue =
        (matrix_t::Identity(currentState.size(), currentState.size()) + flowMapPtr->getLinearApproximation(stateTrajectory[i]) * delta_t) *
        currentState;
    stateTrajectory.emplace_back(nextValue);
  }

  return stateTrajectory;
}

}  // namespace lynx_ode