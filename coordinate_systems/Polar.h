#pragma once
#include <iostream>
#include <cmath>

class Cartesian; 

class Polar {
private:
    double r;
    double theta;

public:
    Polar(double, double);

    friend Cartesian polarToCartesian(const Polar&);
    friend Polar cartesianToPolar(const Cartesian&);
    friend double polarDistance(const Polar&, const Polar&);

    bool isEqual(const Polar&) const;
    void print() const;
};