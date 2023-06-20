#pragma once

#include "ode_integrator/ODEIntegratorBase.h"

namespace lynx_ode {

class EulerForwardIntegrator : public ODEIntegratorBase {
 public:
  EulerForwardIntegrator() : ODEIntegratorBase(){};

 private:
  vector_t integrationStep(const SystemFlowMapBase* flowMapPtr, const vector_t& initialState, scalar_t delta_t) override;

  vector_t eulerforwardStep(const SystemFlowMapBase* flowMapPtr, const vector_t& initialState, scalar_t delta_t);
};

}  // namespace lynx_ode