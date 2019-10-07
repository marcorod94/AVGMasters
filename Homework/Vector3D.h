#ifndef Vector3D_h
#define Vector3D_h
template <class T>
class Vector3D {
public:
	T x;
	T y;
	T z;
	Vector3D();
	Vector3D(T, T, T);
	Vector3D(Vector3D&);
	Vector3D operator +(Vector3D&);
	T Normalize();
	T distance_to(Vector3D&);
};
#endif
