![lynx_ode_logo](https://github.com/manumerous/lynx-ode/assets/18735094/00059cde-f683-409a-bb5d-1974706efd64)

A minimal c++ library containing efficient implementations of common Ordinary Differentail Equations (ODE) solvers that can be used to simulate dynamical systems. 

The following methods are currently included: 
- Explicit Euler (also known as Forward Euler)
- Implicit Euler (also known as Euler Backward)
- 2nd Order Runge-Kutta
- 4th Order Runge-Kutta

## Dependencies

- **Eigen 3.3**. On a debian based linux system (e.g. Ubuntu, Mint) install using ```sudo apt install libeigen3-dev```

### Optional Dependencies for Examples

- **Matplotlibcpp**. Submodule for visualization of the examples. Initialize using: ```make update-submodules```.

Alternatively you can build without the examples by setting `set(BUILD_EXAMPLES OFF)` in CMakeLists.txt. 

## Examples
As an example of how to use the library a simple mass-spring-damper system simulation is included. 
Build the examples by running 

```make build-release```


Then run it by using 

```make run-mass-spring-damper-example```. 

![lynx_ode_examples](https://github.com/manumerous/lynx-ode/assets/18735094/5539bd63-cba0-4ed8-adf1-09ebd5366bb3)
