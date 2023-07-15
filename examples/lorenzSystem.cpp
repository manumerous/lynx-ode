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

class LorenzSystemDyanmics : public SystemDynamicsBase {
 public:
  LorenzSystemDyanmics(scalar_t sigma, scalar_t rho, scalar_t beta) : sigma_(sigma), rho_(rho), beta_(beta) {}

  vector_t computeFlowMap(const vector_t& state) const override {
    Eigen::Matrix<scalar_t, 3, 1> vec(state);
    scalar_t x_dot = sigma_ * (vec.y() - vec.x());
    scalar_t y_dot = vec.x() * (rho_ - vec.z()) - vec.y();
    scalar_t z_dot = vec.x() * vec.y() - beta_ * vec.z();
    vector_t flowMap(3);
    flowMap << x_dot, y_dot, z_dot;
    return flowMap;
  };

 private:
  scalar_t sigma_;
  scalar_t rho_;
  scalar_t beta_;
};

// In this example a mass-spring-damper system (https://en.wikipedia.org/wiki/Mass-spring-damper_model) is simulated.

int main() {
  // Define mass-spring-damper system properties
  // Create mass-spring-damper system as harmonic oscillator
  LorenzSystemDyanmics system = LorenzSystemDyanmics(10, 28, 8 / 3);

  // Create the different types of integrators
  FourthOrderRungeKutta fourthOrderRungeKutta = FourthOrderRungeKutta();
  vector_t initialState(3);
  initialState << 1.0, 3.0, 5.0;

  size_t n_steps = 1000;
  scalar_t integrationHorizon = 10;

  // Create a highly accurate trajectory using a 4th order runge kutta integrator with 10 times more samples
  Trajectory trajectory = fourthOrderRungeKutta.integrate(&system, initialState, n_steps, integrationHorizon);

  // Plot all trajectories using matplotlibcpp
  plt::plot(trajectory.getSingleStateValues(0), trajectory.getSingleStateValues(1));

  plt::title("Lorenz Attractor");

  plt::show();
}