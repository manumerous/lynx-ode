![lynx_ode_logo](https://github.com/manumerous/lynx-ode/assets/18735094/00059cde-f683-409a-bb5d-1974706efd64)

A versatile and light weight like a lynx! This headers only c++ library containing Ordinary Differentail Equations (ODE) solvers that can be used to simulate dynamical systems. 

The following methods are currently included: 
- Explicit Euler (also known as Forward Euler)
- Implicit Euler (also known as Euler Backward)
- 2nd Order Runge-Kutta
- 4th Order Runge-Kutta

## Dependencies

- **Eigen 3.3**. On a debian based linux system (e.g. Ubuntu, Mint) install using ```sudo apt install libeigen3-dev```

### Optional Dependencies for Examples

- **Matplotlibcpp**. Submodule required for visualizating the results of the examples. Initialize using: ```make update-submodules```.

Alternatively you can build without the examples by setting `set(BUILD_EXAMPLES OFF)` in CMakeLists.txt. 

## Build 
Build the examples by running 

```make build-release```


## Examples
As an example of how to use the library multiple examples are included. 

### Lorenz System
The [Lorenz System](https://en.wikipedia.org/wiki/Lorenz_system) is particular system of ordinary differential which has a chaotic solution for certain parameters of the system as seen below.

Run the lorenz system example by using 

```make run-lorenz-example ```. 

![lorenz_system_animation_loop](https://github.com/manumerous/lynx-ode/assets/18735094/07aa6c4d-37a0-46b8-939f-442102f16981)


### Mass Spring Damper System
As an example of how to use the library a mass-spring-damper system simulation is included. 


Run the mass-spring-damper system example by using 

```make run-mass-spring-damper-example```. 

![lynx_ode_examples](https://github.com/manumerous/lynx-ode/assets/18735094/5539bd63-cba0-4ed8-adf1-09ebd5366bb3)
