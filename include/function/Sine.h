#pragma once

#include <cmath>

#include "function/FunctionBase.h"

namespace numerical_integration {

class Sine : public FunctionBase {
 public:
  Sine(){};

  double evaluate(double x) const override { return std::sin(x); };
};

}  // namespace numerical_integration
