cmake_minimum_required(VERSION 3.0)

project(TurboLynxODE VERSION 1.0)

include_directories( ./include ./src ./libs/matplotlib-cpp)

find_package (Eigen3 3.3 REQUIRED NO_MODULE)

add_subdirectory(./libs/matplotlib-cpp)

include_directories(${EIGEN_INCLUDE_DIR})

add_library(${PROJECT_NAME}
  src/ode_integrator/ODEIntegratorBase.cpp
  src/ode_integrator/EulerForwardIntegrator.cpp
  src/ode_integrator/EulerBackwardIntegrator.cpp
  src/ode_integrator/SecondOrderRungeKutta.cpp
)

# add the executable
add_executable(test ./src/main.cpp) 

target_link_libraries(test 
    ${PROJECT_NAME}
    matplotlib_cpp
    Eigen3::Eigen
    )

