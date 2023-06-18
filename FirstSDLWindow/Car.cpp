#include "Car.h"
#include <stdio.h>

Car::Car() {}
Car::~Car() {}

void Car::init(double posx, double posy, double width, double height)
{
	x = posx;
	y = posy;
	w = width;
	h = height;
}
