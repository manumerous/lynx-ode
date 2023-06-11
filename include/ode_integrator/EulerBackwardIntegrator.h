#pragma once

#include "ode_integrator/ODEIntegratorBase.h"

namespace lynx_ode {

class EulerBackwardIntegrator : public ODEIntegratorBase {
 public:
  EulerBackwardIntegrator(){};

  vector_array_t integrate(const SystemFlowMapBase* functionPtr, const vector_t& initialState, size_t n_steps, double delta_t) override;
};

}  // namespace lynx_ode