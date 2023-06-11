#pragma once

#include <vector>
#include "function/FunctionBase.h"

namespace turbo_lynx_ode {

class IntegratorBase {
 public:
  virtual std::vector<double> integrate(const FunctionBase* functionPtr, double initialValue, size_t nSteps, double deltaT) = 0;
};

}  // namespace turbo_lynx_ode