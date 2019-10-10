#include "Vector3D.h"
#include "String.h"
#include <iostream>
int main() {
	// Vetor 3D class
	Vector3D<float> a;
	Vector3D<float> b(1.0, 0.0, 1.0);
	Vector3D<float> c(b);
	Vector3D<float> d;
	d = c + b;
	std::cout << "Vetor 3D class:\n";
	std::cout << "Vector:" << d.x << ", " << d.y << ", " << d.z << std::endl;
	std::cout << "Distance:" << d.distance_to(b) << std::endl;
	d.Normalize();
	std::cout << "Normal:" << d.x << ", " << d.y << ", " << d.z << std::endl;

	// String Class 
	String sa("hello");
	String sb(sa);
	String sc;
	sc = sa + sb;
	std::cout << "\n\nString class:\n";
	std::cout << sa << std::endl;
	std::cout << sc << std::endl;
	if (sa == "hello") {
		std::cout<< sa << " is the same as " << "hello" << std::endl;
	}
	getchar();
}
