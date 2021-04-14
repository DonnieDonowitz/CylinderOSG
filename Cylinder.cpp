#include "Cylinder.h"

#define PI 3.1415927

Cylinder::Cylinder()
{
	geo = new osg::Geometry;
	coord = new osg::Vec3Array;
	norm = new osg::Vec3Array;
	colors = new osg::Vec4Array;
}

void Cylinder::setRadius(float r)
{
	radius = r;
}

void Cylinder::setHeight(float h)
{
	height = h;
}

float Cylinder::getHeight()
{
	return height;
}

float Cylinder::getRadius()
{
	return radius;
}

osg::Geometry* Cylinder::draw()
{
	float slice = (2.0 * PI) / 32.0;

	for (float i = 0.0; i <= 32.0; ++i)
	{
		float x = radius * cos(slice*i);
		float z = radius * sin(slice*i);

		norm->push_back(osg::Vec3(cos(slice*i), 0.0, sin(slice*i)));
		coord->push_back(osg::Vec3(x, 0.0, z));
		norm->push_back(osg::Vec3(cos(slice*i), height, sin(slice*i)));
		coord->push_back(osg::Vec3(x, height, z));
	}
	
	colors->push_back(osg::Vec4(1.0f, 0.0f, 0.0f, 1.0f));

	geo->setVertexArray(coord.get());
	geo->setNormalArray(norm.get());
	geo->setNormalBinding(osg::Geometry::BIND_OVERALL);
	geo->setColorArray(colors.get());
	geo->setColorBinding(osg::Geometry::BIND_PER_PRIMITIVE_SET);
	geo->addPrimitiveSet(new osg::DrawArrays(GL_QUAD_STRIP, 0, coord.get()->size()));
	return geo.get();
}

osg::Vec3Array* Cylinder::getCoord()
{
	return coord.get();
}

osg::Vec3Array* Cylinder::getNorm()
{
	return norm.get();
}

osg::Vec4Array* Cylinder::getColors()
{
	return colors.get();
}