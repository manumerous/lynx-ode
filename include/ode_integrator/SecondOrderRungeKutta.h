#pragma once

#include "ode_integrator/EulerForwardIntegrator.h"

namespace lynx_ode {

class SecondOrderRungeKutta : public EulerForwardIntegrator {
 public:
  SecondOrderRungeKutta() : EulerForwardIntegrator(){};

 private:
  vector_t integrationStep(const SystemFlowMapBase* flowMapPtr, const vector_t& initialState, scalar_t delta_t) override;
};

}  // namespace lynx_ode