#include <iostream>

#include "common/Types.h"
#include "matplotlibcpp.h"
#include "ode_integrator/EulerBackwardIntegrator.h"
#include "ode_integrator/EulerForwardIntegrator.h"
#include "system_dynamics/MassSpringDamperSystem.h"

namespace plt = matplotlibcpp;
using namespace lynx_ode;

int main() {
  MassSpringDamperSystem system = MassSpringDamperSystem(2.0, 0.1);
  EulerForwardIntegrator eulerForwardIntegrator = EulerForwardIntegrator();
  EulerBackwardIntegrator eulerBackwardIntegrator = EulerBackwardIntegrator();
  vector_t initialState(2);
  initialState << 1.0, 0.0;

  size_t n_steps = 1000;
  scalar_t delta_t = 0.01;
  auto eulerForwardTrajectory = eulerForwardIntegrator.integrate(&system, initialState, n_steps, delta_t);
  auto eulerBackwardTrajectory = eulerBackwardIntegrator.integrate(&system, initialState, n_steps, delta_t);

  std::vector<double> x(n_steps + 1), yEulerForward(n_steps + 1), yEulerBackward(n_steps + 1);

  x.emplace_back(0);
  yEulerForward.emplace_back(initialState[0]);
  yEulerBackward.emplace_back(initialState[0]);

  for (int i = 0; i < n_steps; i++) {
    x.emplace_back(i * delta_t);
    yEulerForward.emplace_back(eulerForwardTrajectory[i][0]);
    yEulerBackward.emplace_back(eulerBackwardTrajectory[i][0]);
  }

  plt::plot(x, yEulerForward);
  plt::plot(x, yEulerBackward);
  plt::show();

  return 0;
}