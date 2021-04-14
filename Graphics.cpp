#include "Graphics.h"

Graphics::Graphics()
{
	geo = new osg::Geometry;
	root = new osg::Geode;
}

int Graphics::display()
{
	Cylinder *cyl = new Cylinder();
	cyl->setHeight(1.0);
	cyl->setRadius(0.5);
	geo = cyl->draw();

	root->addDrawable(geo.get());
	delete cyl;
	viewer.setSceneData(root.get());
	return viewer.run();
}
