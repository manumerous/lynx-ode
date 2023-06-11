#pragma once

namespace turbo_lynx_ode {

class SystemFlowMapBase {
 public:
  virtual double getLinearApproximation(double x) const = 0;
};

}  // namespace turbo_lynx_ode
