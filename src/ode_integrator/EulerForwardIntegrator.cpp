#include "ode_integrator/EulerForwardIntegrator.h"

namespace lynx_ode {

vector_t EulerForwardIntegrator::integrationStep(const SystemFlowMapBase* flowMapPtr, const vector_t& initialState, scalar_t delta_t)

{
  return eulerForwardStep(flowMapPtr, initialState, initialState, delta_t);
}

vector_t EulerForwardIntegrator::eulerForwardStep(const SystemFlowMapBase* flowMapPtr, const vector_t& initialState,
                                                  const vector_t& derivativeEvaluationState, scalar_t delta_t, scalar_t step_length) const {
  return initialState + getStepDirection(flowMapPtr, derivativeEvaluationState, step_length) * delta_t;
}

vector_t EulerForwardIntegrator::getStepDirection(const SystemFlowMapBase* flowMapPtr, const vector_t& derivativeEvaluationState,
                                                  scalar_t step_length) const {
  return step_length * flowMapPtr->getLinearApproximation(derivativeEvaluationState) * derivativeEvaluationState;
}

}  // namespace lynx_ode