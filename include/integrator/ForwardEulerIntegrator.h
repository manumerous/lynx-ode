#pragma once

#include "integrator/IntegratorBase.h"

namespace turbo_lynx_ode {

class ForwardEulerIntegrator : public IntegratorBase {
 public:
  ForwardEulerIntegrator(){};

  std::vector<double> integrate(const FunctionBase* functionPtr, double initialValue, size_t nSteps, double deltaT) override;
};

}  // namespace turbo_lynx_ode