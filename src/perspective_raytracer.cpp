#include "ray_tracer.h"

Colour computeColour(Shape *s, Ray *r, Intersection *i){
	// Lamberts cosine rule
	double l = (normalise(reverse(r->direction)) * normalise(s->normal(i->point))) * s->getDiffuse();
	Colour c = s->getColour();
	Colour newc = Colour(l*c.r, l*c.g, l*c.b);
	return newc;
}


void PerspectiveRayTracer::Trace(Image *image, Scene<Shape*>* scene) {
	for (int x = 0; x < image->getWidth(); x++){
		for (int y = 0; y < image->getHeight(); y++){

			// Perspective ray
			// Assume screen is +500 in z axis
			Vector3 dir = Vector3(double(x), double(y), 500.0) - Vector3(image->getWidth() / 2, image->getHeight() / 2, 0);
			Ray *cast = new Ray(Vector3(image->getWidth() / 2, image->getHeight() / 2, 0), dir);

			double t = 0;
			for (deque<Shape*>::iterator it = scene->begin(); it != scene->end(); ++it){
				Intersection i = (*it)->intersect(cast, &t);
				if (t > 0){
					image->setColour(x, y, computeColour(*it, cast, &i));
					break;
				}
			}

			if (t <= 0) {
				image->setColour(x, y, Colour(0.0, 0.0, 0.0));
			}
		}
	}
}