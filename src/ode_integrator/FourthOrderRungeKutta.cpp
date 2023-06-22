#include "ode_integrator/FourthOrderRungeKutta.h"

namespace lynx_ode {

vector_t FourthOrderRungeKutta::integrationStep(const SystemFlowMapBase* flowMapPtr, const vector_t& initialState, scalar_t delta_t)

{
  vector_t f1 = getStepDirection(flowMapPtr, initialState, 1);
  vector_t x1 = initialState + 0.5 * f1 * delta_t;
  vector_t f2 = getStepDirection(flowMapPtr, x1, 1);
  vector_t x2 = initialState + 0.5 * f2 * delta_t;
  vector_t f3 = getStepDirection(flowMapPtr, x2, 1);
  vector_t x3 = initialState + f3 * delta_t;
  vector_t f4 = getStepDirection(flowMapPtr, x3, 1);

  vector_t nextValue = initialState + delta_t * (f1 + 2 * f2 + 2 * f3 + f4) / 6;

  return nextValue;
}

}  // namespace lynx_ode