#include "ode_integrator/SecondOrderRungeKutta.h"

namespace lynx_ode {

vector_t SecondOrderRungeKutta::integrationStep(const SystemFlowMapBase* flowMapPtr, const vector_t& initialState, scalar_t delta_t)

{
  vector_t halfStepValue = eulerForwardStep(flowMapPtr, initialState, delta_t, 0.5);

  vector_t nextValue = eulerForwardStep(flowMapPtr, halfStepValue, delta_t);

  return nextValue;
}

}  // namespace lynx_ode