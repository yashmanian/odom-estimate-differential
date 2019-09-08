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
 *@file Odom.cpp
 *@author Yash Manian
 *@brief Implementation of the methods of class Odom.
 *@brief Estimates Pose and Odometry given Time, Angular Velocity, Encoder values and Steering Angle
 */

#include "Odom.hpp"

// Constructor
Odom::Odom(): wheelRadius(0.2), R(1), D(0.75), encRes(512){}


// Overload Constructor
Odom::Odom(double w, double r, double d, int e): wheelRadius(w), R(r), D(d), encRes(e) {}


// Destructor
Odom::~Odom(){}


// Estimate Pose Function
vector<double> Odom::estimate(double time, double steerAngle, int encTicks, double angVel)
{
	double deltaT;		// Difference between consecutive time stamps
	double deltaTick;	// Differnce between consecutive encoder ticks
	double pos_s, vel_s;	// Position and linear velocity of front wheel
	double w_ang, v;	// Angular velocity and linear velocity component

	vector<double> Pose(3,0);	// Result Pose Vector


	this->circumference = 2*PI*wheelRadius;

	// For initial time stamps and encoder values
	if(this->initFlag == true)
	{
		this->prevT = time;
		this->prevTick = encTicks;
		deltaT = (time - this->prevT);
		deltaTick = encTicks - this->prevTick;
		this->initFlag = false;
	}
	// Once the Odometer has initialized
	else
	{
		deltaT = (time - this->prevT);
		deltaTick = encTicks - this->prevTick;
		this->prevT = time;
		this->prevTick = encTicks;
	}

	// Calculate Velocity and Displacement of wheel based on the delta of time and encoder ticks. 
	pos_s = (double(deltaTick)/double(this->encRes)) * circumference;
	vel_s = pos_s * deltaT;
	this->pos_acc = pos_acc + pos_s;

	// Estimate Odometry and Pose based on the Kinematics of the body
	w_ang = angVel;
	v = vel_s*cos(steerAngle);
	this->theta = this->theta + (w_ang*deltaT);
	this->x = this->x + (v*cos(this->theta)*deltaT);
	this->y = this->y + (v*sin(this->theta)*deltaT);
	Pose[0] = x;
	Pose[1] = y;
	Pose[2] = theta;

	// Return Pose Vector
	return Pose;
}	
