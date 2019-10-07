#include "Vector3D.cpp"
#include "String.h"
#include <iostream>
int main() {
	// Vetor 3D class
	Vector3D<int> a;
	Vector3D<int> b(1, 0, 1);
	Vector3D<int> c(b);
	Vector3D<int> d;
	d = c + b;
	std::cout << "Vetor 3D class:\n";
	std::cout << "Normal:" << d.Normalize() << std::endl;
	std::cout << "Distance:" << d.distance_to(b) << std::endl;

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
