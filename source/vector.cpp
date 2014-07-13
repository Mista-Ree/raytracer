#include "vector.h"

Vector3::Vector3(){}

Vector3::Vector3(float x, float y, float z){
	this->_x = x;
	this->_y = y;
	this->_z = z;
}

Vector3 operator+(const Vector3 &c1, const Vector3 &c2){
	return Vector3(c1._x + c2._x, c1._y + c2._y, c1._z + c2._z);
}

Vector3 operator-(const Vector3 &c1, const Vector3 &c2){
	return Vector3(c1._x - c2._x, c1._y - c2._y, c1._z - c2._z);
}

float operator*(const Vector3 &c1, const Vector3 &c2){
	float res = 0;
	res += c1._x * c2._x;
	res += c1._y * c2._y;
	res += c1._z * c2._z;

	return res;
}

float operator*(const int c1, const Vector3 &c2){
	float res = 0;
	res += c1 * c2._x;
	res += c1 * c2._y;
	res += c1 * c2._z;

	return res;
}

float Vector3::x(){
	return this->_x;
}
float Vector3::y(){
	return this->_y;
}
float Vector3::z(){
	return this->_z;
}

void Vector3::x(float x){
	this->_x = x;
}
void Vector3::y(float y){
	this->_y = y;
}
void Vector3::z(float z){
	this->_z = z;
}

float dot(Vector3 *v1, Vector3 *v2){
	float res = 0;
	res += v1->x() * v2->x();
	res += v1->y() * v2->y();
	res += v1->z() * v2->z();

	return res;

}

Vector3 cross(Vector3 *v1, Vector3 *v2){
	float x = (v1->y() * v2->z()) - (v2->y() * v1->z());
	float y = (v1->x() * v2->z()) - (v2->x() * v1->z());
	float z = (v1->x() * v2->y()) - (v2->x() * v1->y());

	return Vector3(x, y, z);
}