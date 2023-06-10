#include <cmath>

#include "include/function/function.h"

namespace numerical_integration {
class Sine : public Function {
 public:
  Sine();

  virtual double evaluate(double x) override { return std::sin(x); };
}

}  // namespace numerical_integration
