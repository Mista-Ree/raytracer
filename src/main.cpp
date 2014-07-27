#include "sphere.h"
#include "ray.h"
#include "image.h"
#include "intersection.h"

#include <vector>

using namespace std;

Colour computeColour(Shape *s, Ray *r, Intersection *i){
	// Lamberts cosine rule
	double l = (normalise(reverse(r->direction)) * normalise(s->normal(i->point))) * s->getDiffuse();
	Colour c = s->getColour();
	Colour newc = Colour(l*c.r, l*c.g, l*c.b);
	return newc;
}

void Trace(Image *image, vector<Shape*> scene){
	for (int x = 0; x < image->getWidth(); x++){
		for(int y = 0; y < image->getHeight(); y++){
			double t;
			vector<Shape*>::iterator it = scene.begin();

			for (it; it != scene.end(); ++it){
				// Orthogonal ray
				//Ray *cast = new Ray(Vector3(double(x), double(y), 0), Vector3(0, 0, 1.0));

				// Perspective ray
				// Assume screen is +500 in z axis
				Vector3 dir = Vector3(double(x),double(y), 500.0) - Vector3(image->getWidth()/2,image->getHeight()/2,0);
				Ray *cast = new Ray(Vector3(image->getWidth()/2,image->getHeight()/2,0),dir);

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
	//Shape *s = new Sphere(Vector3(960, 540, 1000), 400, Colour(1.0,0.0,0.0));
	//Image image(1920,1080);

	Shape *s = new Sphere(Vector3(250, 250, 700), 100, Colour(1.0,0.0,0.0));
	Image image(500,500);

	//Shape *s = new Sphere(Vector3(50, 50, 50), 20, Colour(1.0,0.0,0.0));
	//Image image(100,100);
	
	vector<Shape*> scene;
	scene.push_back(s);


	// Trace
	Trace(&image, scene);

	image.writeTGA("lambert_03.tga", false);

	return 0;
}