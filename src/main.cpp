#include <iostream>

#include "common/Types.h"
#include "matplotlibcpp.h"
#include "ode_integrator/EulerForwardIntegrator.h"
#include "system_dynamics/MassSpringDamperSystem.h"

namespace plt = matplotlibcpp;
using namespace lynx_ode;

int main() {
  MassSpringDamperSystem system = MassSpringDamperSystem(2.0, 0.2);
  EulerForwardIntegrator forwardEulerIntegrator = EulerForwardIntegrator();
  vector_t initialState(2);
  initialState << 1.0, 0.0;

  size_t n_steps = 1000;
  scalar_t delta_t = 0.01;
  auto stateTrajectory = forwardEulerIntegrator.integrate(&system, initialState, n_steps, delta_t);

  std::vector<double> x(n_steps + 1), y(n_steps + 1);

  x.emplace_back(0);
  y.emplace_back(initialState[0]);

  for (int i = 0; i < n_steps; i++) {
    x.emplace_back(i * delta_t);
    y.emplace_back(stateTrajectory[i][0]);
  }

  plt::plot(x, y);
  plt::show();

  return 0;
}