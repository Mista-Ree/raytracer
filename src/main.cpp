#include "sphere.h"
#include "ray.h"
#include "image.h"
#include <vector>

void Trace(Image *image, vector<Shape*> scene){
	for (int x = 0; x < image->getWidth(); x++){
		for(int y = 0; y < image->getHeight(); y++){
			float t;
			vector<Shape*>::iterator it = scene.begin();

			for (it; it != scene.end(); ++it){
				(*it)->intersect(new Ray(Vector3(float(x), float(y), 0), Vector3(0, 0, 1.0f)), &t);
				if (t > 0){
					image->setColour(x, y, Colour(0.0f,0.0f,0.0f));
				}
				else{
					image->setColour(x, y, Colour(255.0f, 255.0f, 255.0f));
				}
			}
		}
	}
}

int main(int argc, char *argv[]){
	Sphere *s = new Sphere(Vector3(960, 540, 500), 200);

	
	vector<Shape*> scene;
	scene.push_back(s);

	Image image(1920,1080);

	// Trace
	Trace(&image, scene);

	image.writeTGA("test.tga", false);

	return 0;
}