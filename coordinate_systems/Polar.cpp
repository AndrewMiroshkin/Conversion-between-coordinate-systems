#include "Libraries.h"
#include "Cmake.h"

class Polar {
private:
	double r;
	double theta;

public:
	Polar(double radius, double angle) : r(radius), theta(angle) {}

	friend Cartesian polarToCartesian(const Polar&);

	friend Polar cartesianToPolar(const Cartesian&);

	friend double polarDistance(const Polar&, const Polar&);

	bool isEqual(const Polar& other) const {
		return (fabs(r - other.r) < 1e-6) && (fabs(theta - other.theta) < 1e-6);
	}

	void print() {
		std::cout << "Полярна система координат: (r: " << r << ", theta: " << theta << ")\n";
	}
};

