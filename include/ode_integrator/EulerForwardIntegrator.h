#pragma once

#include "ode_integrator/ODEIntegratorBase.h"

namespace lynx_ode {

class EulerForwardIntegrator : public ODEIntegratorBase {
 public:
  EulerForwardIntegrator() : ODEIntegratorBase(){};

 protected:
  virtual vector_t integrationStep(const SystemFlowMapBase* flowMapPtr, const vector_t& initialState, scalar_t delta_t) override;

  vector_t eulerForwardStep(const SystemFlowMapBase* flowMapPtr, const vector_t& initialState, scalar_t delta_t,
                            scalar_t step_length = 1.0);
};

}  // namespace lynx_ode