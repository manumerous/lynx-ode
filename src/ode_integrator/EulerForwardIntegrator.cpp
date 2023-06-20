#include "ode_integrator/EulerForwardIntegrator.h"

namespace lynx_ode {

vector_t EulerForwardIntegrator::integrationStep(const SystemFlowMapBase* flowMapPtr, const vector_t& initialState, scalar_t delta_t)

{
  return eulerforwardStep(flowMapPtr, initialState, delta_t);
}

vector_t EulerForwardIntegrator::eulerforwardStep(const SystemFlowMapBase* flowMapPtr, const vector_t& initialState, scalar_t delta_t) {
  vector_t nextValue =
      (matrix_t::Identity(initialState.size(), initialState.size()) + flowMapPtr->getLinearApproximation(initialState) * delta_t) *
      initialState;

  return nextValue;
}

}  // namespace lynx_ode