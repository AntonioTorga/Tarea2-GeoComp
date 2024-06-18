#include <iostream>
#include <cassert>
#include <vector>
#include "Utils.h"
#include "Poligono.h"

using namespace std;
int main() {
	//std::vector<Punto<int>> rand_points = randomPoints(10);

	//std::cout << "Random points" << std::endl;
	//for (int i = 0; i < rand_points.size(); i++) {
	//	std::cout << rand_points[i] << std::endl;
	//}
	std::vector<Punto<int>> points = {
		Punto(100,27),
		Punto(95,93),
		Punto(-44,99),
		Punto(-43,29),
		Punto(54,-62),
		Punto(8,98),
		Punto(96,24),
		Punto(85,-13),
		Punto(31,-82),
		Punto(-100,50)
	};

	std::cout << "Points" << std::endl;
	for (int i = 0; i < points.size(); i++) {
		std::cout << points[i] << std::endl;
	}

	Poligono<int> gift_wrapped = giftWrapping(points);
	std::cout << "Convex hull with gift wrapping" << std::endl;
	std::cout << gift_wrapped << std::endl;

	Poligono<int> graham_scan = grahamScan(points);
	std::cout << "Convex hull with graham scan" << std::endl;
	std::cout << graham_scan << std::endl;

	//std::vector<Punto<int>> otros_puntos = {Punto(-29, 33), Punto(-20, -4), Punto(32, -28), Punto(-1, 50), Punto(-11, -5), Punto(-49, 31), Punto(-34, -43), Punto(6, -44), Punto(-35, 40), Punto(-15, 36)};

	//std::cout << "Points" << std::endl;
	//for (int i = 0; i < otros_puntos.size(); i++) {
	//	std::cout << otros_puntos[i] << std::endl;
	//}

	//Poligono<int> gift_wrapped_two = giftWrapping(otros_puntos);
	//std::cout << "Convex Hull" << std::endl;
	//std::cout << gift_wrapped_two << std::endl;
	//return 0;
}