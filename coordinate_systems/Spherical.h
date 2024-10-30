#pragma once
#include <iostream>
#include <cmath>

class Cartesian; 

class Spherical {
private:
    double r;
    double theta;
    double phi;

public:
    Spherical(double, double, double);

    friend Cartesian sphericalToCartesian(const Spherical&);
    friend Spherical cartesianToSpherical(const Cartesian&);
    friend double throughSphereDistance(const Spherical&, Spherical&);
    friend double greatCircleDistance(const Spherical&, const Spherical&);

    bool isEqual(const Spherical&) const;
    void print() const;
};
