#include <function/Sine.h>
#include <integrator/ForwardEulerIntegrator.h>
#include <iostream>

int main() {
  numerical_integration::Sine sine = numerical_integration::Sine();
  numerical_integration::ForwardEulerIntegrator forwardEulerIntegrator = numerical_integration::ForwardEulerIntegrator();
  auto integrationTrajectory = forwardEulerIntegrator.integrate(&sine, 1, 100, 0.1);
  for (double& point : integrationTrajectory) {
    std::cout << point << std::endl;
  }

  return 0;
}