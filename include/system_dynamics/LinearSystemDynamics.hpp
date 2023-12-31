#include "system_dynamics/SystemDynamicsBase.hpp"

namespace lynx_ode {

class LinearSystemDynamics : public SystemDynamicsBase {
 public:
  LinearSystemDynamics(matrix_t A) : A_(A){};
  vector_t computeFlowMap(const vector_t& state) const override { return getLinearApproximation(state) * state; };

  matrix_t getLinearApproximation(const vector_t& state) const { return A_; };

 private:
  matrix_t A_;
};

}  // namespace lynx_ode
