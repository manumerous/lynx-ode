#include <function/Sine.h>
#include <integrator/ForwardEulerIntegrator.h>
#include <iostream>

int main() {
  turbo_lynx_ode::Sine sine = turbo_lynx_ode::Sine();
  turbo_lynx_ode::ForwardEulerIntegrator forwardEulerIntegrator = turbo_lynx_ode::ForwardEulerIntegrator();
  auto integrationTrajectory = forwardEulerIntegrator.integrate(&sine, 1, 100, 0.1);
  for (double& point : integrationTrajectory) {
    std::cout << point << std::endl;
  }

  return 0;
}