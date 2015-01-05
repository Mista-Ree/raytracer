#ifndef _RAY_TRACER_H
#define _RAY_TRACER_H

#include "image.h"
#include "scene.h"

class RayTracer {
public:
	virtual void Trace(Image *image, Scene<Shape*>* scene) = 0;
};

class PerspectiveRayTracer : public RayTracer {
public:
	virtual void Trace(Image *image, Scene<Shape*>* scene);
};

#endif