
#pragma once

#include <array>
#include <cstddef>
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/StdVector>
#include <vector>

namespace turbo_lynx_ode {

/** Scalar type. */
using scalar_t = double;
/** Scalar trajectory type. */
using scalar_array_t = std::vector<scalar_t>;

/** Dynamic-size vector type. */
using vector_t = Eigen::Matrix<scalar_t, Eigen::Dynamic, 1>;
/** Dynamic vector's trajectory type. */
using vector_array_t = std::vector<vector_t>;

/** Dynamic-size matrix type. */
using matrix_t = Eigen::Matrix<scalar_t, Eigen::Dynamic, Eigen::Dynamic>;
/** Dynamic matrix's trajectory type. */
using matrix_array_t = std::vector<matrix_t>;

/** Eigen scalar type. */
using eigen_scalar_t = Eigen::Matrix<scalar_t, 1, 1>;
/** Eigen scalar trajectory type. */
using eigen_scalar_array_t = std::vector<eigen_scalar_t>;

}  // namespace turbo_lynx_ode
