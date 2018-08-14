# Odometry Estimate
## Overview
The objective of this project was to create a function that can estimate the 2D odometry and pose (x, y, heading) for a robot with tricycle kinematics, using a wheel encoder and IMU data. The library initializes default robot parameters, but can be overloaded to incorporate custom values for the Robot geometry, Wheel Radius and Encoder Resolution. The robot geometry is defined by r, which is the distance between the front and back wheels, and d, which is the wheel base.The class intializes the time to zero and assumes that the encoder gives out negative values when moving in reverse. The range for the steering angle is between -90/+90 degrees. The default parameters for the class are initialized to the following values:

Wheel Radius = 0.2 m
Distance between front and back wheels (r) = 1 m
Distance between rear wheels (d) = 0.75 m
Encoder resolution = 512
Initial Pose = [0, 0, 0]

The assumption is made that the Pose exists in a Right Handed Coordinate System.

* Inputs: 
```
time (sec)			-> double
steeringAngle (rad)	-> double
encTicks (integer)	-> int
angVel (Rad/s)		-> double
```

* Outputs:
```
Pose (m, m, rad) 	-> vector<double>
```

Example code on how to use the library has been included in the cpp file src/main.cpp. The values for time stamps, angular velocities and encoder ticks is read from a .csv file in this instance. Outputs are written to a .csv file in the Outputs folder. 


## How to build and run the tests
* To build and run demo:
```
mkdir build
cd build
cmake ..
make
cd src
./OdomEstimate
```
* Run the tests:
```
cd build
./test/matrix-test
```
To use these functions in your own code. Add the include directory path to the compiler debugging. Include to the start of your code and call the functions:
* To use:
```
#include "Odom.hpp" 
```

## Doxygen Documentation
To generate Doxygen Documentation in HTML and LaTEX, follow the next steps:

```
cd OdomEstimate
mkdir <documentation_folder_name>
cd <documentation_folder_name>
doxygen -g <config_file_name>
```
Inside the configuration file, update:
```
PROJECT_NAME = 'your project name'
INPUT = ../
```
Run and generate the documents by running the next command:
```
doxygen <config_file_name>
```
All these steps have already been performed in this project.

To view the documents easily, access `class_odom.html` and `main_8cpp.html` with your browser.

## License

MIT License

Copyright (c) 2018 Yash Manian

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

