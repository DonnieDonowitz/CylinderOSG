#pragma once
#include "Cylinder.h"
#include <vector>
#include <osgViewer/Viewer>
#include <osg/Geode>
#include <osg/Geometry>

class Graphics
{
public:
	Graphics();
	int display();
	
private:
	osgViewer::Viewer viewer;
	osg::ref_ptr<osg::Geometry> geo;
	osg::ref_ptr<osg::Geode> root;
};

