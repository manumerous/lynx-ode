#pragma once

#include "ode_integrator/EulerForwardIntegrator.h"

namespace lynx_ode {

class ForthOrderRungeKutta : public EulerForwardIntegrator {
 public:
  ForthOrderRungeKutta() : EulerForwardIntegrator(){};

 private:
  vector_t integrationStep(const SystemFlowMapBase* flowMapPtr, const vector_t& initialState, scalar_t delta_t) override;
};

}  // namespace lynx_ode