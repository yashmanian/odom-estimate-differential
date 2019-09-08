/** MIT License
Copyright (c) 2018 Yash Manian
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 *@copyright Copyright 2018 Yash Manian
 *@file Odom.h
 *@author Yash Manian
 *@brief Header file with definitions for class Odom.
 *@brief The following methods are used to estimate Pose and calculate Odometry
 */


#ifndef ODOM_H
#define ODOM_H

#include <iostream>
#include <math.h>
#include <vector>

#define PI 3.14159265358979323846

using namespace std;

/**
 *@brief Definition of the Odometer class. It contains all the functions and variables required to calculate Pose.
 *@brief It uses Time, Encoder Values, Steering Angles and Angular Velocity to do so.
 */
class Odom
{
private:
	double wheelRadius;	// Wheel Radius (in meters)
	double R;			// Distance from steering center to center of axle (in meters)
	double D;			// Distance between wheels (in meters)
	double circumference = 0;	// Circumference of wheels (in meters)
	int encRes;		// Ticks per revolution for the encoder (integer)
	double pos_acc = 0;		// Position over time
	bool initFlag = true;		// Flag for first reading
	double x = 0, y = 0, theta = 0; // Position coordinates
	double prevT = 0, prevTick = 0; // Encoder Calculation variables


public:
	// Constructor
	/**
	 *@brief Constructor for the Odometer class. 
	 *@brief Initializes System variables such as Wheel Radius, Encoder Resolution, and the geometry of the Robot.
	 */
	Odom();


	// Overload Constructor
	/**
	 *@brief Overload Constructor for the Odometer class. 
	 *@brief Overloads the constructor to allow user defined values for the Wheel Radius, Encoder resolution and Robot geometry.
	 */
	Odom(double w, double r, double d, int e);


	// Destructor
	/**
	 *@brief Destructor for the Odometer class. 
	 */
	~Odom();

	// Estimate function
	/**
	 *@brief Estimate Pose Function
	 *@brief Function that takes in the Time Stamp, Steering Angle, Encoder Ticks and the Angular Velocity.
	 *@brief Calculates delta between the time stamps and encoder ticks.
	 *@brief Determines Velocity and Displacement of the Wheel with the Traction encoder.
	 *@brief Based on the geometry of the robot and the steering angles, calculates the total Odometry and Pose.
	 *@brief Return Pose Vector.
	 */	
	vector<double> estimate(double time, double steerAngle, int encTicks, double angVel);	
};


#endif