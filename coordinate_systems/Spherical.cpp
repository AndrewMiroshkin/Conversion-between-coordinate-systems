#include "Spherical.h"
#include "Cartesian.h"

Spherical::Spherical(double radius, double azimuth, double polar) : r(radius), theta(azimuth), phi(polar) {}

Cartesian sphericalToCartesian(const Spherical& spherical) {
    return Cartesian(
        spherical.r * sin(spherical.phi) * cos(spherical.theta),
        spherical.r * sin(spherical.phi) * sin(spherical.theta),
        spherical.r * cos(spherical.phi)
    );
}

Spherical cartesianToSpherical(const Cartesian& cartesian) {
    double r = sqrt(pow(cartesian.x, 2) + pow(cartesian.y, 2) + pow(cartesian.z, 2));
    return Spherical(r, atan2(cartesian.y, cartesian.x), acos(cartesian.z / r));
}

double throughSphereDistance(const Spherical& fPoint, Spherical& sPoint) {
    return sqrt(pow(fPoint.r, 2) + pow(sPoint.r, 2) - 2 * fPoint.r * sPoint.r *
        (sin(fPoint.theta) * sin(sPoint.theta) * cos(fPoint.phi - sPoint.phi) + cos(fPoint.theta) * cos(sPoint.theta)));
}

double greatCircleDistance(const Spherical& fPoint, const Spherical& sPoint) {
    return fPoint.r * acos(sin(fPoint.phi) * sin(sPoint.phi) + cos(fPoint.phi) * cos(sPoint.phi) * cos(fPoint.theta - sPoint.theta));
}

bool Spherical::isEqual(const Spherical& other) const {
    return (fabs(r - other.r) < 1e-6) && (fabs(theta - other.theta) < 1e-6) && (fabs(phi - other.phi) < 1e-6);
}

void Spherical::print() const {
    std::cout << "—ферична система координат: (r: " << r << ", theta: " << theta << ", phi: " << phi << ")\n";
}
