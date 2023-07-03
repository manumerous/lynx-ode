#include <iostream>

#include "common/Types.h"
#include "matplotlibcpp.h"
#include "ode_integrator/EulerBackwardIntegrator.h"
#include "ode_integrator/EulerForwardIntegrator.h"
#include "ode_integrator/FourthOrderRungeKutta.h"
#include "ode_integrator/SecondOrderRungeKutta.h"

namespace plt = matplotlibcpp;

using namespace lynx_ode;

// Create the system flow map of the mass spring damper system

class MassSpringDamperSystem : public SystemFlowMapBase {
 public:
  MassSpringDamperSystem(scalar_t natuaralFrequency, scalar_t dampingRatio) {
    A << 0.0, 1.0, -natuaralFrequency * natuaralFrequency, -2 * natuaralFrequency * dampingRatio;
  };

  matrix_t getLinearApproximation(const vector_t& state) const override { return A; };

 private:
  matrix2_t A;
};

int main() {
  MassSpringDamperSystem system = MassSpringDamperSystem(2.0, 0.1);

  // Create the different types of integrators
  EulerForwardIntegrator eulerForwardIntegrator = EulerForwardIntegrator();
  EulerBackwardIntegrator eulerBackwardIntegrator = EulerBackwardIntegrator();
  SecondOrderRungeKutta secondOrderRungeKutta = SecondOrderRungeKutta();
  FourthOrderRungeKutta fourthOrderRungeKutta = FourthOrderRungeKutta();
  vector_t initialState(2);
  initialState << 1.0, 0.0;

  size_t n_steps = 400;
  scalar_t integrationHorizon = 10;

  // Create a highly accurate trajectory using a 4th order runge kutta integrator with 10 times more samples
  Trajectory groundTruthTrajectory = fourthOrderRungeKutta.integrate(&system, initialState, n_steps * 10, integrationHorizon);

  // Create trajectories for the first order integrators
  Trajectory eulerForwardTrajectory = eulerForwardIntegrator.integrate(&system, initialState, n_steps, integrationHorizon);
  Trajectory eulerBackwardTrajectory = eulerBackwardIntegrator.integrate(&system, initialState, n_steps, integrationHorizon);

  // The higher order integrators have a much smaller local error ( delta_t³ and delta_t⁵ respectively)
  // Therefore they can achieve higher accuracy even at much higher step length.
  Trajectory rungeKutta2Trajectory = secondOrderRungeKutta.integrate(&system, initialState, n_steps / 5, integrationHorizon);
  Trajectory rungeKutta4Trajectory = fourthOrderRungeKutta.integrate(&system, initialState, n_steps / 10, integrationHorizon);

  // Plot all trajectories using matplotlibcpp
  plt::plot(groundTruthTrajectory.getTimeStamps(), groundTruthTrajectory.getSingleStateValues(0));
  plt::plot(eulerForwardTrajectory.getTimeStamps(), eulerForwardTrajectory.getSingleStateValues(0));
  plt::plot(eulerBackwardTrajectory.getTimeStamps(), eulerBackwardTrajectory.getSingleStateValues(0));
  plt::plot(rungeKutta2Trajectory.getTimeStamps(), rungeKutta2Trajectory.getSingleStateValues(0));
  plt::plot(rungeKutta4Trajectory.getTimeStamps(), rungeKutta4Trajectory.getSingleStateValues(0));
  plt::show();

  return 0;
}