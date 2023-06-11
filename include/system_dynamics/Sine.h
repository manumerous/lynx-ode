#pragma once

#include <cmath>

#include "system_dynamics/SystemFlowMapBase.h"

namespace turbo_lynx_ode {

class Sine : public SystemFlowMapBase {
 public:
  Sine(){};

  double evaluate(double x) const override { return std::sin(x); };
};

}  // namespace turbo_lynx_ode
