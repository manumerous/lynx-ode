/******************************************************************************
Copyright (c) 2023, Manuel Yves Galliker. All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

* Neither the name of the copyright holder nor the names of its
  contributors may be used to endorse or promote products derived from
  this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
******************************************************************************/

#include <cmath>
#include <iostream>

#include "matplotlibcpp.h"

#include "common/Types.hpp"
#include "ode_integrator/EulerBackwardIntegrator.hpp"
#include "ode_integrator/EulerForwardIntegrator.hpp"
#include "ode_integrator/FourthOrderRungeKutta.hpp"
#include "ode_integrator/SecondOrderRungeKutta.hpp"

namespace plt = matplotlibcpp;

using namespace lynx_ode;

// Create the system flow map for a harmonic oscillator

class HarmonicOscillator : public SystemFlowMapBase {
 public:
  HarmonicOscillator(scalar_t natuaralFrequency, scalar_t dampingRatio) {
    A << 0.0, 1.0, -natuaralFrequency * natuaralFrequency, -2 * natuaralFrequency * dampingRatio;
  };

  matrix_t getLinearApproximation(const vector_t& state) const override { return A; };

 private:
  matrix2_t A;
};

// In this example a harmonic oscillator (at the example of a mass-spring-damper system) is simulated.

int main() {
  // Define mass-spring-damper system properties
  scalar_t mass = 1;        // Kg
  scalar_t k_spring = 4;    // N/m
  scalar_t c_damper = 0.5;  // N * s / m

  scalar_t naturalFrequency = std::sqrt(k_spring / mass);
  scalar_t dampingRatio = c_damper / (2 * mass * naturalFrequency);

  // Create mass-spring-damper system as harmonic oscillator
  HarmonicOscillator system = HarmonicOscillator(naturalFrequency, dampingRatio);

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
  plt::plot(groundTruthTrajectory.getTimeStamps(), groundTruthTrajectory.getSingleStateValues(0), {{"label", "Ground Truth"}});
  plt::plot(eulerForwardTrajectory.getTimeStamps(), eulerForwardTrajectory.getSingleStateValues(0), {{"label", "Euler Forward"}});
  plt::plot(eulerBackwardTrajectory.getTimeStamps(), eulerBackwardTrajectory.getSingleStateValues(0), {{"label", "Euler Backward"}});
  plt::plot(rungeKutta2Trajectory.getTimeStamps(), rungeKutta2Trajectory.getSingleStateValues(0), {{"label", "2nd Order Runge Kutta"}});
  plt::plot(rungeKutta4Trajectory.getTimeStamps(), rungeKutta4Trajectory.getSingleStateValues(0), {{"label", "4th Order Runge Kutta"}});

  plt::title("Simulated Mass-Spring-Damper System");
  plt::xlabel("Time [s]");
  plt::ylabel("Position [m]");
  plt::legend();

  plt::show();

  return 0;
}