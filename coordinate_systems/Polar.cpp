#include "Polar.h"
#include "Cartesian.h"

Polar::Polar(double radius, double angle) : r(radius), theta(angle) {}

Cartesian polarToCartesian(const Polar& polar) {
    return Cartesian(polar.r * cos(polar.theta), polar.r * sin(polar.theta));
}

Polar cartesianToPolar(const Cartesian& cartesian) {
    return Polar(sqrt(pow(cartesian.x, 2) + pow(cartesian.y, 2)), atan2(cartesian.y, cartesian.x));
}

double polarDistance(const Polar& fPoint, const Polar& sPoint) {
    return sqrt(pow(fPoint.r, 2) + pow(sPoint.r, 2) - 2 * fPoint.r * sPoint.r * cos(sPoint.theta - fPoint.theta));
}

bool Polar::isEqual(const Polar& other) const {
    return (fabs(r - other.r) < 1e-6) && (fabs(theta - other.theta) < 1e-6);
}

void Polar::print() const {
    std::cout << "Полярна система координат: (r: " << r << ", theta: " << theta << ")\n";
}
