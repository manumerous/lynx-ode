#pragma once

#include <cmath>

#include "function/FunctionBase.h"

namespace turbo_lynx_ode {

class Sine : public FunctionBase {
 public:
  Sine(){};

  double evaluate(double x) const override { return std::sin(x); };
};

}  // namespace turbo_lynx_ode
