#include "Figure.h"

void Figure::setPosition(vec p) 
{
	position = p;
}

void Figure::setRotation(double angle, vec p)
{
	rotation.push_back(angle);
	for (double d : p.v) 
	{
		rotation.push_back(d);
	}
}

void Figure::setColor(vec c)
{
	color = c;
}

vec Figure::getColor() 
{
	return color;
}

vec Figure::getPosition()
{
	return position;
}

std::vector<double> Figure::getRotation()
{
	return rotation;
}