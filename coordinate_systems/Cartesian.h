#pragma once
#include <iostream>
#include <cmath>

class Polar; 
class Spherical; 

class Cartesian {
private:
    double x;
    double y;
    double z;

public:
    Cartesian();
    Cartesian(double, double);
    Cartesian(double, double, double);

    friend Cartesian polarToCartesian(const Polar&);
    friend Polar cartesianToPolar(const Cartesian&);
    friend Cartesian sphericalToCartesian(const Spherical&);
    friend Spherical cartesianToSpherical(const Cartesian&);
    friend double cartesianDistance2D(const Cartesian&, const Cartesian&);
    friend double cartesianDistance3D(const Cartesian&, const Cartesian&);

    bool isEqual(const Cartesian&) const;
    void print2D() const;
    void print3D() const;
};