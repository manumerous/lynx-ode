#pragma once

namespace turbo_lynx_ode {

class FunctionBase {
 public:
  virtual double evaluate(double x) const = 0;
};

}  // namespace turbo_lynx_ode
