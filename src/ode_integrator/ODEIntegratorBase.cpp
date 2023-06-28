#include "ode_integrator/ODEIntegratorBase.h"

namespace lynx_ode {

Trajectory ODEIntegratorBase::integrate(const SystemFlowMapBase* flowMapPtr, const vector_t& initialState, size_t n_steps,
                                        scalar_t integrationHorizonTime) {
  Trajectory stateTrajectory = Trajectory(n_steps + 1);
  stateTrajectory.appendValue(0.0, initialState);
  scalar_t delta_t = integrationHorizonTime / n_steps;

  for (int i = 1; i < n_steps + 1; i++) {
    stateTrajectory.appendValue(i * delta_t, integrationStep(flowMapPtr, stateTrajectory.getValues()[i - 1], delta_t));
  }

  return stateTrajectory;
}

}  // namespace lynx_ode