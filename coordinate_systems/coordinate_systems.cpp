#include <iostream>
#include <cmath>
#include <vector>
#include <windows.h>

#include "Timer.h"
#include "Cmake.h"

static HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
#define White SetConsoleTextAttribute(hOUTPUT, 0x000f);
#define Green SetConsoleTextAttribute(hOUTPUT, 0x000a);
#define Red SetConsoleTextAttribute(hOUTPUT, 0x000c);
#define Cyan SetConsoleTextAttribute(hOUTPUT, 0x0003);
#define PI 3.14159265358979323846

// Перехід між системами координат
void task1() {
	bool correct = true;

	// Двовимірний простір: Декартова та полярна системи координат 
	{
		std::vector<Cartesian> cartesianPoints2D;
		std::vector<Polar> convertedPolarPoints;
		std::vector<Polar> polarPoints = {
			{0, 0},
			{5, PI / 6},
			{3, PI / 4},
			{8, PI / 3}
		};

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

		if (correct) { Green std::cout << "Перетворення виконані коректно.\n\n"; White	}
		else { Red std::cout << "Помилка в перетвореннях.\n\n"; White }
	}

	// Тривимірний простір: Декартова та сферична системи координат
	{
		std::vector<Cartesian> cartesianPoints3D;
		std::vector<Spherical> convertedSphericalPoints;
		std::vector<Spherical> sphericalPoints = {
			{1, 1, 1},
			{5, PI / 6, PI / 4},
			{3, PI / 4, PI / 3},
			{8, PI / 3, PI / 6}
		};

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
		if (correct) { Green std::cout << "Перетворення виконані коректно.\n\n"; White }
		else { Red std::cout << "Помилка в перетвореннях.\n\n"; White }
	}
}

// Розрахунок відстаней у сферичній системі координат:
void task2() {
	std::vector<Cartesian> cartesianPoints = {
		{8, 12},
		{7, 11},
		{3, -6, 8},
		{-1, 5, -15}
	};
	std::cout << "Двовимірний простір - відстань між двома точками у декартовій системі координат: " << cartesianDistance2D(cartesianPoints[0], cartesianPoints[1]) << '\n' 
		<< "Тривимірний простір - відстань між двома точками у декартовій системі координат: " << cartesianDistance3D(cartesianPoints[2], cartesianPoints[3]) << "\n\n";
	
	std::vector<Polar> polarPoints = {
		{5, PI / 6},
		{8, PI / 3}
	};
	std::cout << "Пряма відстань між двома точками у полярній системі координат: " << polarDistance(polarPoints[0], polarPoints[1]) << "\n\n";

	std::vector<Spherical> sphericalPoints = {
		{5, PI / 6, PI / 4},
		{3, PI / 4, PI / 3},
	};
	std::cout << "Пряма відстань між двома точками у сферичній системі координат (через об'єм сфери): " << throughSphereDistance(sphericalPoints[0], sphericalPoints[1]) << '\n'
		<< "Дугова відстань між двома точками на поверхні сфери (велика колова відстань): " << greatCircleDistance(sphericalPoints[0], sphericalPoints[1]) << "\n\n";
}

// Бенчмарки продуктивності:
void task3() {
	std::vector<Cartesian> cartesianPoints;
	std::vector<Polar> polarPoints;
	std::vector<Spherical> sphericalPoints;


	for (int i = 0; i < 100000; ++i)
		cartesianPoints.push_back({ (double)(rand() % 100), (double)(rand() % 100), (double)(rand() % 100) });

	for (int i = 0; i < 100000; ++i)
		polarPoints.push_back({ (double)(rand() % 100), (double)(rand() % 100) });

	for (int i = 0; i < 100000; ++i)
		sphericalPoints.push_back({ (double)(rand() % 100), (double)(rand() % 100), (double)(rand() % 100) });

	{
		std::cout << "Відстань між двома точками у декартовій системі координат 2D\n";
		Timer t;
		for (int i = 0; i < 100000; i += 2)
			cartesianDistance2D(cartesianPoints[i], cartesianPoints[i + 1]);
	}
	std::cout << '\n';

	{
		std::cout << "Відстань між двома точками у декартовій системі координат 3D\n";
		Timer t;
		for (int i = 0; i < 100000; i += 2)
			cartesianDistance3D(cartesianPoints[i], cartesianPoints[i + 1]);
	}
	std::cout << '\n';

	{
		std::cout << "Відстань між двома точками у полярній системі координат\n";
		Timer t;
		for (int i = 0; i < 100000; i += 2)
			polarDistance(polarPoints[i], polarPoints[i + 1]);
	}
	std::cout << '\n';

	{
		std::cout << "Відстань між двома точками у сферичній системі координат (через об'єм сфери)\n";
		Timer t;
		for (int i = 0; i < 100000; i += 2)
			throughSphereDistance(sphericalPoints[i], sphericalPoints[i + 1]);
	}
	std::cout << '\n';

	{
		std::cout << "Відстань між двома точками на поверхні сфери (велика колова відстань)\n";
		Timer t;
		for (int i = 0; i < 100000; i += 2)
			greatCircleDistance(sphericalPoints[i], sphericalPoints[i + 1]);
	}
}

int main() {
	setlocale(LC_ALL, "ru");
	system("chcp 1251");
	system("cls");	

	Cyan printf("---------------------------------------------------------------------------------\n\n"); White

	task1();

	Cyan printf("---------------------------------------------------------------------------------\n\n"); White

	task2();

	Cyan printf("---------------------------------------------------------------------------------\n\n"); White

	task3();

	Cyan printf("\n---------------------------------------------------------------------------------\n\n"); White

	return 0;
}