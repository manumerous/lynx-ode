#pragma once

#include "ode_integrator/ODEIntegratorBase.h"

namespace lynx_ode {

class EulerBackwardIntegrator : public ODEIntegratorBase {
 public:
  EulerBackwardIntegrator() : ODEIntegratorBase(){};

 private:
  vector_t integrationStep(const SystemFlowMapBase* flowMapPtr, const vector_t& initialState, scalar_t delta_t) override;
};

}  // namespace lynx_ode