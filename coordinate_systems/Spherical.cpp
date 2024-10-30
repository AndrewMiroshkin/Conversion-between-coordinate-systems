#include "Libraries.h"
#include "Cmake.h"

class Spherical {
private:
	double r;
	double theta;
	double phi;

public:
	Spherical(double radius, double azimuth, double polar) : r(radius), theta(azimuth), phi(polar) {}

	friend Cartesian sphericalToCartesian(const Spherical&);

	friend Spherical cartesianToSpherical(const Cartesian&);

	friend double throughSphereDistance(const Spherical&, Spherical&);

	friend double greatCircleDistance(const Spherical&, const Spherical&);

	bool isEqual(const Spherical& other) const {
		return (fabs(r - other.r) < 1e-6) && (fabs(theta - other.theta) < 1e-6) && (fabs(phi - other.phi) < 1e-6);
	}

	void print() {
		std::cout << "—ферична система координат: (r: " << r << ", theta: " << theta << ", phi: " << phi << ")\n";
	}
};