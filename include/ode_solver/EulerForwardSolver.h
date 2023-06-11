#pragma once

#include "ode_solver/ODESolverBase.h"

namespace turbo_lynx_ode {

class EulerForwardSolver : public ODESolverBase {
 public:
  EulerForwardSolver(){};

  vector_array_t integrate(const SystemFlowMapBase* functionPtr, const vector_t& initialState, size_t n_steps, double delta_t) override;
};

}  // namespace turbo_lynx_ode