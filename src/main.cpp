#include <iostream>

#include "common/Types.h"
#include "matplotlibcpp.h"
#include "ode_integrator/EulerBackwardIntegrator.h"
#include "ode_integrator/EulerForwardIntegrator.h"
#include "ode_integrator/FourthOrderRungeKutta.h"
#include "ode_integrator/SecondOrderRungeKutta.h"
#include "system_dynamics/MassSpringDamperSystem.h"

namespace plt = matplotlibcpp;

using namespace lynx_ode;

int main() {
  MassSpringDamperSystem system = MassSpringDamperSystem(2.0, 0.1);
  EulerForwardIntegrator eulerForwardIntegrator = EulerForwardIntegrator();
  EulerBackwardIntegrator eulerBackwardIntegrator = EulerBackwardIntegrator();
  SecondOrderRungeKutta secondOrderRungeKutta = SecondOrderRungeKutta();
  FourthOrderRungeKutta fourthOrderRungeKutta = FourthOrderRungeKutta();
  vector_t initialState(2);
  initialState << 1.0, 0.0;

  size_t n_steps = 1000;
  scalar_t integrationHorizon = 20;
  Trajectory groundTruthTrajectory = fourthOrderRungeKutta.integrate(&system, initialState, n_steps * 10, integrationHorizon);
  Trajectory eulerForwardTrajectory = eulerForwardIntegrator.integrate(&system, initialState, n_steps, integrationHorizon);
  Trajectory eulerBackwardTrajectory = eulerBackwardIntegrator.integrate(&system, initialState, n_steps, integrationHorizon);
  Trajectory rungeKutta2Trajectory = secondOrderRungeKutta.integrate(&system, initialState, n_steps / 5, integrationHorizon);
  Trajectory rungeKutta4Trajectory = fourthOrderRungeKutta.integrate(&system, initialState, n_steps / 10, integrationHorizon);

  plt::plot(groundTruthTrajectory.getTimeStamps(), groundTruthTrajectory.getSingleStateValues(0));
  plt::plot(eulerForwardTrajectory.getTimeStamps(), eulerForwardTrajectory.getSingleStateValues(0));
  plt::plot(eulerBackwardTrajectory.getTimeStamps(), eulerBackwardTrajectory.getSingleStateValues(0));
  plt::plot(rungeKutta2Trajectory.getTimeStamps(), rungeKutta2Trajectory.getSingleStateValues(0));
  plt::plot(rungeKutta4Trajectory.getTimeStamps(), rungeKutta4Trajectory.getSingleStateValues(0));
  // plt::legend(loc = "upper right");
  plt::show();

  return 0;
}