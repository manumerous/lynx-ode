
#include "integrator/ForwardEulerIntegrator.h"

namespace numerical_integration {

std::vector<double> ForwardEulerIntegrator::integrate(const FunctionBase* functionPtr, double initialValue, size_t nSteps, double delta_t) {
  std::vector<double> stateTrajectory;
  stateTrajectory.reserve(nSteps + 1);
  stateTrajectory.emplace_back(initialValue);

  for (int i = 0; i < nSteps; i++) {
    double nextValue = stateTrajectory[i] + functionPtr->evaluate(stateTrajectory[i]) * delta_t;
    stateTrajectory.emplace_back(nextValue);
  }

  return stateTrajectory;
}

}  // namespace numerical_integration