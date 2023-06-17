#include "ode_integrator/EulerBackwardIntegrator.h"

namespace lynx_ode {

vector_t EulerBackwardIntegrator::integrationStep(const SystemFlowMapBase* flowMapPtr, const vector_t& initialState, scalar_t delta_t) {
  vector_t nextValue =
      (matrix_t::Identity(initialState.size(), initialState.size()) - flowMapPtr->getLinearApproximation(initialState) * delta_t)
          .inverse() *
      initialState;

  return nextValue;
}

}  // namespace lynx_ode