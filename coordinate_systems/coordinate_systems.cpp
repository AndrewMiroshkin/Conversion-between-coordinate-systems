#include <iostream>
#include <cmath>
#include <vector>

#define PI 3.14159265358979323846

class Cartesian; 
class Spherical;
class Polar;

class Polar {
private:
	double r; 
	double theta;

public:
	Polar(double radius, double angle) : r(radius), theta(angle) {}

	friend Cartesian polarToCartesian(const Polar&);

	friend Polar cartesianToPolar(const Cartesian&);

	bool isEqual(const Polar& other) const {
		return (fabs(r - other.r) < 1e-6) && (fabs(theta - other.theta) < 1e-6);
	}

	void print() {
		std::cout << "Полярна система координат: (r: " << r << ", theta: " << theta << ")\n";
	}
};

class Spherical {
private:
	double r; 
	double theta; 
	double phi; 

public:
	Spherical(double radius, double azimuth, double polar) : r(radius), theta(azimuth), phi(polar) {}

	friend Cartesian sphericalToCartesian(const Spherical&);

	friend Spherical cartesianToSpherical(const Cartesian&);

	bool isEqual(const Spherical& other) const {
		return (fabs(r - other.r) < 1e-6) && (fabs(theta - other.theta) < 1e-6) && (fabs(phi - other.phi) < 1e-6);
	}

	void print() {
		std::cout << "Сферична система координат: (r: " << r << ", theta: " << theta << ", phi: " << phi << ")\n";
	}
};

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

	void print2D() {
		std::cout << "Декартова система координат: (x: " << x << ", y: " << y << ")\n";
	}

	void print3D() {
		std::cout << "Декартова система координат: (x: " << x << ", y: " << y << ", z: " << z << ")\n";
	}
};

Cartesian polarToCartesian(const Polar& polar) {
	return Cartesian(polar.r * cos(polar.theta), polar.r * sin(polar.theta));
}

Polar cartesianToPolar(const Cartesian& cartesian) {
	return Polar(sqrt(pow(cartesian.x, 2) + pow(cartesian.y, 2)), atan2(cartesian.y, cartesian.x));
}

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

int main() {
	setlocale(LC_ALL, "ru");
	system("chcp 1251");
	system("cls");

	bool correct = true;
	std::vector<Cartesian> cartesianPoints2D; 
	std::vector<Polar> convertedPolarPoints;
	std::vector<Polar> polarPoints = {
		{0, 0},
		{5, PI / 6},
		{3, PI / 4},
		{8, PI / 3}
	}; 

	std::vector<Cartesian> cartesianPoints3D;
	std::vector<Spherical> convertedSphericalPoints;
	std::vector<Spherical> sphericalPoints = {
		{1, 1, 1},
		{5, PI / 6, PI / 4},
		{3, PI / 4, PI / 3},
		{8, PI / 3, PI / 6}
	};
	
	// Двовимірний простір: Декартова та полярна системи координат
	{
		for (const auto& polar : polarPoints) {
			cartesianPoints2D.push_back(polarToCartesian(polar));
		}

		for (const auto& cartesian : cartesianPoints2D) {
			convertedPolarPoints.push_back(cartesianToPolar(cartesian));
		}

		for (auto n : cartesianPoints2D) n.print2D();
		std::cout << '\n';
		for (auto n : convertedPolarPoints) n.print();
		std::cout << '\n';

		for (size_t i = 0; i < polarPoints.size(); ++i) {
			if (!polarPoints[i].isEqual(convertedPolarPoints[i])) {
				correct = false;
				break;
			}
		}

		if (correct) std::cout << "Перетворення виконані коректно.\n\n";
		else std::cout << "Помилка в перетвореннях.\n\n";
	}

	// Тривимірний простір: Декартова та сферична системи координат
	{
		for (const auto& spherical : sphericalPoints) {
			cartesianPoints3D.push_back(sphericalToCartesian(spherical));
		}

		for (const auto& cartesian : cartesianPoints3D) {
			convertedSphericalPoints.push_back(cartesianToSpherical(cartesian));
		}

		for (auto n : cartesianPoints3D) n.print3D();
		std::cout << '\n';
		for (auto n : convertedSphericalPoints) n.print();
		std::cout << '\n';

		for (size_t i = 0; i < sphericalPoints.size(); ++i) {
			if (!sphericalPoints[i].isEqual(convertedSphericalPoints[i])) {
				correct = false;
				break;
			}
		}

		if (correct) std::cout << "Перетворення виконані коректно.\n";
		else std::cout << "Помилка в перетвореннях.\n";
	}

	return 0;
}