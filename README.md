
![lynx_ode_logo](https://github.com/manumerous/lynx-ode/assets/18735094/d2e58833-0f8e-4f13-a4f7-39ae9577021f)

A minimal c++ library containing efficient implementations of common Ordinary Differentail Equations (ODE) solvers that can be used to simulate dynamical systems. 

The following methods are currently included: 
- Explicit Euler (also known as Forward Euler)
- Implicit Euler (also known as Euler Backward)
- 2nd Order Runge-Kutta
- 4th Order Runge-Kutta

## Dependencies

The only dependency for this library is Eigen 3.3.On a debian based linux system (e.g. Ubuntu, Mint) it can easily be installed using `sudo apt install libeigen3-dev`.

#### Optional Dependencies for examples
To visualize the provided examples you need to initialize the matplotlibcpp submodule using `make update-submodules`. 
