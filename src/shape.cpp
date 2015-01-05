#include "shape.h"

Shape::Shape() {
// default constructor
}

Shape::Shape(Vector3 position) : pos(position) {

}

Vector3 Shape::getPosition() {
	return pos;
}