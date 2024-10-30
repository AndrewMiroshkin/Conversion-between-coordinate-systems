#include "Libraries.h"
#include "Cmake.h"

class Cartesian {
private:
	double x;
	double y;
	double z;

public:
	Cartesian() : x(0), y(0), z(0) {}

	Cartesian(double x, double y) : x(x), y(y), z(0) {}

	Cartesian(double x, double y, double z) : x(x), y(y), z(z) {}

	friend Cartesian polarToCartesian(const Polar&);

	friend Polar cartesianToPolar(const Cartesian&);

	friend Cartesian sphericalToCartesian(const Spherical&);

	friend Spherical cartesianToSpherical(const Cartesian&);

	friend double cartesianDistance2D(const Cartesian&, const Cartesian&);

	friend double cartesianDistance3D(const Cartesian&, const Cartesian&);

	void print2D() {
		std::cout << "Декартова система координат: (x: " << x << ", y: " << y << ")\n";
	}

	void print3D() {
		std::cout << "Декартова система координат: (x: " << x << ", y: " << y << ", z: " << z << ")\n";
	}
};