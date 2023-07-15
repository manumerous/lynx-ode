cmake_minimum_required(VERSION 3.0)

project(TurboLynxODE VERSION 1.0)

# Set to OFF when you don't need the examples
set(BUILD_EXAMPLES ON)

include_directories( ./include ./src)
if(BUILD_EXAMPLES)
  include_directories(./libs/matplotlib-cpp)
endif(BUILD_EXAMPLES)

find_package (Eigen3 3.3 REQUIRED NO_MODULE)

add_subdirectory(./libs/matplotlib-cpp)

include_directories(${EIGEN_INCLUDE_DIR})

##############
## Examples ##
##############

if(BUILD_EXAMPLES)

  add_executable(massSpringDamperSystem ./examples/massSpringDamperSystem.cpp) 

  target_link_libraries(massSpringDamperSystem 
      matplotlib_cpp
      Eigen3::Eigen
      )
      
endif(BUILD_EXAMPLES)



