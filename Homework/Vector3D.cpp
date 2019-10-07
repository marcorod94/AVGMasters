#include "Vector3D.h"
#include <math.h>

template <class T>
Vector3D<T>::Vector3D() {
	x = 0;
	y = 0;
	z = 0;
}

template <class T>
Vector3D<T>::Vector3D(T x, T y, T z) : x(x), y(y), z(z) {}

template <class T>
Vector3D<T>::Vector3D(Vector3D<T>& vector3d) : x(vector3d.x), y(vector3d.y), z(vector3d.z) {}

template<class T>
Vector3D<T> Vector3D<T>::operator +(Vector3D<T>& vector) {
	Vector3D<T> aux(x + vector.x, y + vector.y, z + vector.z);
	return aux;
}

template <class T>
T Vector3D<T>::Normalize() {
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

template <class T>
T Vector3D<T>::distance_to(Vector3D<T>& vector) {
	return sqrt(pow(x - vector.x, 2) + pow(y - vector.y, 2) + pow(z - vector.z, 2));
}