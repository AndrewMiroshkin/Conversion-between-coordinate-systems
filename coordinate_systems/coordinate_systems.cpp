#include <iostream>
#include <cmath>
#include <vector>

#define PI 3.14159265358979323846

class Cartesian; 
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

	void print() const {
		std::cout << "Полярна система координат: (r: " << r << ", theta: " << theta << ")\n";
	}
};

class Cartesian {
private:
	double x;
	double y;

public:
	Cartesian(double x, double y) : x(x), y(y) {}

	friend Cartesian polarToCartesian(const Polar&);

	friend Polar cartesianToPolar(const Cartesian&);

	void print() const {
		std::cout << "Декартова система координат: (x: " << x << ", y: " << y << ")\n";
	}
};

Cartesian polarToCartesian(const Polar& polar) {
	return Cartesian(polar.r * cos(polar.theta), polar.r * sin(polar.theta));
}

Polar cartesianToPolar(const Cartesian& cartesian) {
	return Polar(sqrt(cartesian.x * cartesian.x + cartesian.y * cartesian.y), atan2(cartesian.y, cartesian.x));
}

int main() {
	setlocale(LC_ALL, "ru");
	system("chcp 1251");
	system("cls");

	bool correct = true;
	std::vector<Cartesian> cartesianPoints; 
	std::vector<Polar> convertedPolarPoints; 
	std::vector<Polar> polarPoints = {
		{5, 0},
		{5, PI / 6},
		{3, PI / 4},
		{7, PI / 3}
	}; 
	
	for (const auto& polar : polarPoints) {
		cartesianPoints.push_back(polarToCartesian(polar));
	}

	for (const auto& cartesian : cartesianPoints) {
		convertedPolarPoints.push_back(cartesianToPolar(cartesian));
	}

	for (auto n : convertedPolarPoints) n.print();
	std::cout << '\n';
	for (auto n : cartesianPoints) n.print();
	std::cout << '\n';

	for (size_t i = 0; i < polarPoints.size(); ++i) {
		if (!polarPoints[i].isEqual(convertedPolarPoints[i])) {
			correct = false;
			break;
		}
	}

	if (correct) std::cout << "Перетворення виконані коректно.\n";
	else std::cout << "Помилка в перетвореннях.\n";

	return 0;
}