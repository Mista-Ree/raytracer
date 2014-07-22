#include "vector.h"

Vector3::Vector3(){}

Vector3::Vector3(double x, double y, double z){
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

double operator*(const Vector3 &c1, const Vector3 &c2){
	double res = 0;
	res += c1._x * c2._x;
	res += c1._y * c2._y;
	res += c1._z * c2._z;

	return res;
}

Vector3 operator*(const double c1, const Vector3 &c2){
	return Vector3(c1*c2._x, c1*c2._y, c1*c2._z);
}

double Vector3::x(){
	return this->_x;
}
double Vector3::y(){
	return this->_y;
}
double Vector3::z(){
	return this->_z;
}

void Vector3::x(double x){
	this->_x = x;
}
void Vector3::y(double y){
	this->_y = y;
}
void Vector3::z(double z){
	this->_z = z;
}

double dot(Vector3 *v1, Vector3 *v2){
	double res = 0;
	res += v1->x() * v2->x();
	res += v1->y() * v2->y();
	res += v1->z() * v2->z();

	return res;

}

Vector3 cross(Vector3 *v1, Vector3 *v2){
	double x = (v1->y() * v2->z()) - (v2->y() * v1->z());
	double y = (v1->x() * v2->z()) - (v2->x() * v1->z());
	double z = (v1->x() * v2->y()) - (v2->x() * v1->y());

	return Vector3(x, y, z);
}

Vector3 normalise(Vector3 v){
	double modulus = mod(v);
	double x, y, z;

	x = v._x / modulus;
	y = v._y / modulus;
	z = v._z / modulus;

	return Vector3(x, y, z);
}

double mod(Vector3 v){
	double x = v._x, y = v._y, z = v._z;

	return sqrt(x*x + y*y + z*z);
}
