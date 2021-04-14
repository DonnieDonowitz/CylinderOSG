#pragma once
#include "Figure.h"
#include <osg\Geometry>

class Cylinder: public Figure
{
public:
	Cylinder();
	osg::Geometry* draw();
	float getRadius();
	float getHeight();
	void setHeight(float);
	void setRadius(float);
	osg::Vec3Array* getCoord();
	osg::Vec3Array* getNorm();
	osg::Vec4Array* getColors();

private:
	float radius, height;
	osg::ref_ptr<osg::Vec3Array> coord, norm;
	osg::ref_ptr<osg::Geometry> geo;
	osg::ref_ptr<osg::Vec4Array> colors;
};

