#include "sphere.h"
#include "ray.h"
#include "image.h"
#include "intersection.h"

#include <vector>

Colour computeColour(Shape *s, Ray *r, Intersection *i){
	// Lamberts cosine rule
	double l = (normalise(r->direction) * normalise(s->normal(i->point))) * s->getDiffuse();
	Colour c = s->getColour();
	return Colour(l*c.r, l*c.g, l*c.b);
}

void Trace(Image *image, vector<Shape*> scene){
	for (int x = 0; x < image->getWidth(); x++){
		for(int y = 0; y < image->getHeight(); y++){
			double t;
			vector<Shape*>::iterator it = scene.begin();

			for (it; it != scene.end(); ++it){
				Ray *cast = new Ray(Vector3(double(x), double(y), 0), Vector3(0, 0, 1.0));
				Intersection i = (*it)->intersect(cast, &t);

				if (t > 0){
					image->setColour(x, y, computeColour(*it, cast, &i));
				}
				else{
					image->setColour(x, y, Colour(0.0, 0.0, 0.0));
				}
			}
		}
	}
}



int main(int argc, char *argv[]){
	Shape *s = new Sphere(Vector3(250, 250, 250), 100, Colour(1.0,0.0,0.0));

	
	vector<Shape*> scene;
	scene.push_back(s);

	Image image(500,500);

	// Trace
	Trace(&image, scene);

	image.writeTGA("test.tga", false);

	return 0;
}