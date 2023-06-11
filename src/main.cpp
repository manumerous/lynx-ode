#include <ode_solver/EulerForwardSolver.h>
#include <system_dynamics/SpringDamperSystem.h>
#include <iostream>

int main() {
  lynx_ode::SpringDamperSystem system = lynx_ode::SpringDamperSystem(2.0, 0.5);
  lynx_ode::EulerForwardSolver forwardEulerIntegrator = lynx_ode::EulerForwardSolver();
  lynx_ode::vector_t initialState(2);
  initialState << 1.0, 0.0;
  auto stateTrajectory = forwardEulerIntegrator.integrate(&system, initialState, 100, 0.1);
  for (const lynx_ode::vector_t& state : stateTrajectory) {
    std::cout << state.transpose() << std::endl;
  }

  return 0;
}