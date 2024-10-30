#include "Cmake.h"

Cartesian::Cartesian() : x(0), y(0), z(0) {}

Cartesian::Cartesian(double x, double y) : x(x), y(y), z(0) {}

Cartesian::Cartesian(double x, double y, double z) : x(x), y(y), z(z) {}

double cartesianDistance2D(const Cartesian& fPoint, const Cartesian& sPoint) {
    return sqrt(pow((sPoint.x - fPoint.x), 2) + pow((sPoint.y - fPoint.y), 2));
}

double cartesianDistance3D(const Cartesian& fPoint, const Cartesian& sPoint) {
    return sqrt(pow((sPoint.x - fPoint.x), 2) + pow((sPoint.y - fPoint.y), 2) + pow((sPoint.z - fPoint.z), 2));
}

bool Cartesian::isEqual(const Cartesian& other) const {
    return (fabs(x - other.x) < 1e-6) && (fabs(y - other.y) < 1e-6) && (fabs(z - other.z) < 1e-6);
}

void Cartesian::print2D() const {
    std::cout << "Декартова система координат: (x: " << x << ", y: " << y << ")\n";
}

void Cartesian::print3D() const {
    std::cout << "Декартова система координат: (x: " << x << ", y: " << y << ", z: " << z << ")\n";
}