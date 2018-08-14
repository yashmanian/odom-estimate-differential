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
 *@file main.cpp
 *@author Yash Manian
 *@brief Main function that brings it all together.
 */

#include <iostream>
#include <math.h>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>

#include "Odom.hpp"

#define PI 3.14159265358979323846


using namespace std;

/**
 *@brief Function main that runs the main algorithm.
 *@brief Main function reads Encoder and time from a csv file.
 *@brief Parses file and passes values into a function.
 *@brief Saves the results in the Outputs folder.
 *@return 0
 */

int main()
{
	// Initialize System Variables
	double R = 1.0;
	double D = 0.75;
	double wheelRadius = 0.2;
	int encRes = 512;
	double time, steerAngle, angVel;
	int encTicks;
	vector<double> Pose;
	steerAngle = 0*(PI/180);
	
	// Initialize Class
	Odom Odometer(wheelRadius, R, D, encRes);

	// File OP variables
	int nCol = 4;
	string lineA;

	// Filename parsing to make multiple runs more convenient
	string filepathIP = "../../Files/IP/input";
	string filepathOP = "../../Files/Outputs/output";
	string ext =  ".csv";
	string fileKey = "10";
	string filenameIP = filepathIP + fileKey + ext;
	string filenameOP = filepathOP + fileKey + ext;

	const char* F_op = filenameOP.c_str();

	cout << filenameIP << " " << filenameOP << endl;

	// Read file with encoder values	
	ifstream ifs(filepathIP + fileKey + ext);

	// Open Output File	
	ofstream ofs;
	ofs.open("../Files/Outputs/temp.csv", ios::out | ios::binary);

	// Check for error opening the file
	if(!ifs.is_open())
	{
		cout << "ERROR: Couldn't open file" << endl;
		return 1;
	}

	// Loop reading file and parsing values to pass into the estimate function 
	while(ifs.good())
	{
		// Parse line in the file to get variables
		while(getline(ifs, lineA))
		{
			istringstream streamA(lineA);
			for (int n = 0; n < nCol; n++)
			{
				if(n == 0)
				{
					streamA >> time;
				}
				else if(n == 1)
				{
					streamA >> encTicks;
				}
				else if(n == 2)
				{
					streamA >> steerAngle;
				}
				else if(n == 3)
				{
					streamA >> angVel;
				}
			}
			// Test values are in degrees. Comment out this line when using Radians!!
			steerAngle = steerAngle*PI/180;	

			Pose = Odometer.estimate(time, steerAngle, encTicks, angVel);
			ofs << Pose[0] << " " << Pose[1] << " " << Pose[2] << "\n";
			cout << "X: " << Pose[0] << " Y: " << Pose[1] << " THETA: " << Pose[2] << " ,angVel: " << angVel << endl;
		}
	}

	ifs.close();
	ofs.close();
	//remove(F_op);
	//rename("../Files/Outputs/temp.csv", F_op);

	return 0;
}