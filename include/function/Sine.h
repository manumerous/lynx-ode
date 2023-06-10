#include <cmath>

#include "include/function/FunctionBase.h"

namespace numerical_integration {
class Sine : public FunctionBase {
 public:
  Sine();

  virtual double evaluate(double x) override { return std::sin(x); };
}

}  // namespace numerical_integration
