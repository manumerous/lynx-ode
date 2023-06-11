#pragma once

#include <cmath>

#include "system_dynamics/SystemFlowMapBase.h"

namespace lynx_ode {

class SpringDamperSystem : public SystemFlowMapBase {
 public:
  SpringDamperSystem(scalar_t natuaralFrequency, scalar_t dampingRatio) {
    A << 0.0, 1.0, -natuaralFrequency * natuaralFrequency, -2 * natuaralFrequency * dampingRatio;
  };

  matrix_t getLinearApproximation(const vector_t& state) const override { return A; };

 private:
  matrix2_t A;
};

}  // namespace lynx_ode
