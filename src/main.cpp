#include "sphere.h"
#include "image.h"
#include "scene.h"
#include "ray_tracer.h"

using namespace std;

int main(int argc, char *argv[]){
	//Shape *s = new Sphere(Vector3(960, 540, 1000), 400, Colour(1.0,0.0,0.0));
	//Image image(1920,1080);

	Shape *s1 = new Sphere(Vector3(250, 250, 700), 100, Colour(1.0, 0.0, 0.0));
	Shape *s2 = new Sphere(Vector3(400, 250, 700), 50, Colour(1.0, 0.0, 0.0));
	Image image(500, 500);

	// Create new scene
	Scene<Shape*> *scene = new ShapeScene();
	scene->add(s1);
	scene->add(s2);

	// Create new PerspectiveRayTracer
	RayTracer *rayTracer = new PerspectiveRayTracer();
	rayTracer->Trace(&image, scene);


	image.writeTGA("lambert_03.tga", false);

	return 0;
}