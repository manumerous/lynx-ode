#include <ode_solver/EulerForwardSolver.h>
#include <system_dynamics/Sine.h>
#include <iostream>

int main() {
  lynx_ode::Sine sine = lynx_ode::Sine();
  lynx_ode::EulerForwardSolver forwardEulerIntegrator = lynx_ode::EulerForwardSolver();
  lynx_ode::vector_t initialState(1);
  initialState << 1.0;
  auto stateTrajectory = forwardEulerIntegrator.integrate(&sine, initialState, 100, 0.1);
  for (const lynx_ode::vector_t& state : stateTrajectory) {
    std::cout << state << std::endl;
  }

  return 0;
}