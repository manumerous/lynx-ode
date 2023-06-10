#include <cmath>

#include "include/function/AbstractFunction.h"

namespace numerical_integration {
class Sine : public AbstractFunction {
 public:
  Sine();

  virtual double evaluate(double x) override { return std::sin(x); };
}

}  // namespace numerical_integration
