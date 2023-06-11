#include <ode_solver/EulerForwardSolver.h>
#include <system_dynamics/Sine.h>
#include <iostream>

int main() {
  turbo_lynx_ode::Sine sine = turbo_lynx_ode::Sine();
  turbo_lynx_ode::EulerForwardSolver forwardEulerIntegrator = turbo_lynx_ode::EulerForwardSolver();
  turbo_lynx_ode::vector_t initialState(1);
  initialState << 1.0;
  auto stateTrajectory = forwardEulerIntegrator.integrate(&sine, initialState, 100, 0.1);
  for (const turbo_lynx_ode::vector_t& state : stateTrajectory) {
    std::cout << state << std::endl;
  }

  return 0;
}