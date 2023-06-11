#pragma once

#include "integrator/IntegratorBase.h"

namespace numerical_integration {

class ForwardEulerIntegrator : public IntegratorBase {
 public:
  ForwardEulerIntegrator(){};

  std::vector<double> integrate(const FunctionBase* functionPtr, double initialValue, size_t nSteps, double deltaT) override;
};

}  // namespace numerical_integration