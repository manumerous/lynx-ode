
#pragma once

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

}  // namespace lynx_ode
