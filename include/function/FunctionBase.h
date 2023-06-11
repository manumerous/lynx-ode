#pragma once

namespace numerical_integration {

class FunctionBase {
 public:
  virtual double evaluate(double x) const = 0;
};

}  // namespace numerical_integration
