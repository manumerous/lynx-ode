cmake_minimum_required(VERSION 3.0)

project(TurboLynxODE VERSION 1.0)


include_directories()

# include files
include_directories( ./include ./src)

find_package (Eigen3 3.3 REQUIRED NO_MODULE)

include_directories(${EIGEN_INCLUDE_DIR})

add_library(${PROJECT_NAME}
  src/integrator/ForwardEulerIntegrator.cpp
)

# add the executable
add_executable(test ./src/main.cpp) 

target_link_libraries(test 
    ${PROJECT_NAME}
    Eigen3::Eigen
    )

