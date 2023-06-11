
#pragma once

#include <array>
#include <cstddef>
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/StdVector>
#include <vector>

namespace lynx_ode {

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

template <typename SCALAR_T>
using VECTOR_T = Eigen::Matrix<SCALAR_T, -1, 1>;
template <typename SCALAR_T>
using VECTOR2_T = Eigen::Matrix<SCALAR_T, 2, 1>;
template <typename SCALAR_T>
using VECTOR3_T = Eigen::Matrix<SCALAR_T, 3, 1>;
template <typename SCALAR_T>
using VECTOR4_T = Eigen::Matrix<SCALAR_T, 4, 1>;
template <typename SCALAR_T>
using VECTOR6_T = Eigen::Matrix<SCALAR_T, 6, 1>;
template <typename SCALAR_T>
using VECTOR12_T = Eigen::Matrix<SCALAR_T, 12, 1>;
template <typename SCALAR_T>
using MATRIX2_T = Eigen::Matrix<SCALAR_T, 2, 2>;
template <typename SCALAR_T>
using MATRIX3_T = Eigen::Matrix<SCALAR_T, 3, 3>;
template <typename SCALAR_T>
using MATRIX4_T = Eigen::Matrix<SCALAR_T, 4, 4>;
template <typename SCALAR_T>
using MATRIX6_T = Eigen::Matrix<SCALAR_T, 6, 6>;

using vector2_t = VECTOR2_T<scalar_t>;
using vector3_t = VECTOR3_T<scalar_t>;
using vector4_t = VECTOR4_T<scalar_t>;
using vector6_t = VECTOR6_T<scalar_t>;
using vector12_t = VECTOR12_T<scalar_t>;
using matrix2_t = MATRIX2_T<scalar_t>;
using matrix3_t = MATRIX3_T<scalar_t>;
using matrix4_t = MATRIX4_T<scalar_t>;
using matrix6_t = MATRIX6_T<scalar_t>;
using quaternion_t = Eigen::Quaternion<scalar_t>;

}  // namespace lynx_ode
