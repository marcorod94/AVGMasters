#ifndef Vector3D_h
#define Vector3D_h
#include <math.h>

template <class T>
class Vector3D {
public:
	T x;
	T y;
	T z;
	Vector3D();
	Vector3D(T, T, T);
	Vector3D(const Vector3D&);
	Vector3D operator +(const Vector3D&);
	void Normalize();
	T distance_to(const Vector3D&);
};

template <class T>
Vector3D<T>::Vector3D() : x(0), y(0), z(0) {}

template <class T>
Vector3D<T>::Vector3D(T x, T y, T z) : x(x), y(y), z(z) {}

template <class T>
Vector3D<T>::Vector3D(const Vector3D<T>& vector3d) : x(vector3d.x), y(vector3d.y), z(vector3d.z) {}

template<class T>
Vector3D<T> Vector3D<T>::operator +(const Vector3D<T>& vector) {
	return Vector3D<T> (x + vector.x, y + vector.y, z + vector.z);
}

template <class T>
void Vector3D<T>::Normalize() {
	T module = 1 / sqrt(x * x + y * y + z * z);
	x = x * module;
	y = y * module;
	z = z * module;
}

template <class T>
T Vector3D<T>::distance_to(const Vector3D<T>& vector) {
	return sqrt((x - vector.x) * (x - vector.x) + (y - vector.y) * (y - vector.y)  + (z - vector.z) * (z - vector.z));
}
#endif
