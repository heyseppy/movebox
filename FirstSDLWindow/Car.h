#pragma once
#include <stdio.h>
#include <iostream>

class Car {

public:
	Car();
	~Car();
	void init(double posx, double posy, double width, double height);
	void driveForward(double x);
	void turn(double angle);

private:
	double x;
	double y;
	double w;
	double h;


};