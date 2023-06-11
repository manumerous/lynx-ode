#pragma once

#include <vector>
#include "function/FunctionBase.h"

namespace numerical_integration {

class IntegratorBase {
 public:
  virtual std::vector<double> integrate(const FunctionBase* functionPtr, double initialValue, size_t nSteps, double deltaT) = 0;
};

}  // namespace numerical_integration