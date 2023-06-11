#pragma once

#include <cmath>

#include "system_dynamics/SystemFlowMapBase.h"

namespace turbo_lynx_ode {

class Sine : public SystemFlowMapBase {
 public:
  Sine(){};

  matrix_t getLinearApproximation(const vector_t& state) const override {
    matrix_t linearApproximation(1, 1);
    linearApproximation << std::sin(state[0]);
    return linearApproximation;
  };
};

}  // namespace turbo_lynx_ode
