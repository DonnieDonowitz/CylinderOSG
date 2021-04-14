#pragma once
#include <vector>

struct vec {
	std::vector<double> v;
};

class Figure
{
public:
	void setPosition(vec);
	void setRotation(double, vec);
	void setColor(vec);
	vec getColor();
	vec getPosition();
	std::vector<double> getRotation();
	virtual void setHeight(float) = 0;
	virtual void setRadius(float) = 0;

private:
	vec position;
	std::vector<double> rotation;
	vec color;
};

