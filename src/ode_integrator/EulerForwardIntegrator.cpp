#include "ode_integrator/EulerForwardIntegrator.h"

namespace lynx_ode {

vector_t EulerForwardIntegrator::integrationStep(const SystemFlowMapBase* flowMapPtr, const vector_t& initialState, scalar_t delta_t)

{
  return eulerForwardStep(flowMapPtr, initialState, delta_t);
}

vector_t EulerForwardIntegrator::eulerForwardStep(const SystemFlowMapBase* flowMapPtr, const vector_t& initialState, scalar_t delta_t,
                                                  scalar_t step_length) {
  vector_t nextValue = (matrix_t::Identity(initialState.size(), initialState.size()) +
                        step_length * flowMapPtr->getLinearApproximation(initialState) * delta_t) *
                       initialState;

  return nextValue;
}

}  // namespace lynx_ode