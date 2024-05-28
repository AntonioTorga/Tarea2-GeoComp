#include "Poligono.h"
#include <iostream>
#include <cassert>

using namespace std;
int main() {
	cout << "Point constructor test with pt1(1, 2), pt2(3, 4), pt3(2, 2), pt4(-1, -2)" << endl;
	Punto<int> pt1(1,2);
	assert(pt1.get_coords() == make_pair(1, 2));
	Punto<int> pt2(3, 4);
	Punto<int> pt3(2, 2);
	Punto<int> pt4(-1, -2);


	cout << "Cout test pt1: " << pt1 << endl;
	cout << "Distance test between pt1 and pt3: " << pt1.distance(pt3);
	assert(pt1.distance(pt3) == 1);
	cout << "Operator== test between pt1 and Punto<int>(1,2): " << (pt1 == Punto<int>(1, 2)) << endl;
	assert(pt1 == Punto<int>(1, 2));
	cout << "Operator== test between pt1 and pt2: " << (pt1 == Punto<int>(1, 2)) << endl;
	assert(!(pt1 == pt2));

	cout << endl;

	cout << "Poligon constructor test with pt1,pt2,pt3,pt4. One in CW and one in CWW" << endl;

	vector<Punto<int>> vertices_cw = {pt1,pt2,pt3,pt4}; //clockwise
	vector<Punto<int>> vertices_ccw = {pt4,pt3,pt2,pt1}; //counterclockwise
	Poligono<int> poligono_cw(vertices_cw);
	Poligono<int> poligono_ccw(vertices_ccw);

	cout << "Cout test, Poligon CW: " << poligono_cw << endl; 
	cout << "check_ccw test on Poligon CW: " << poligono_cw.check_ccw() << endl;
	assert(!poligono_cw.check_ccw());
	cout << "Cout test, Poligon CCW: " << poligono_ccw << endl;
	cout << "check_ccw test on Poligon CCW: " << poligono_ccw.check_ccw() << endl;
	assert(poligono_ccw.check_ccw());
	cout << "Operator[] test, Second vertex of Poligon CW: " << poligono_cw[1] << endl;
	assert(poligono_cw[1] == Punto<int>(3,4));
	cout << endl;

	cout << "Vector constructor test, Vector<int> V1(3,4)" << endl;
	Vector<int> V1(3, 4);
	cout << "Vector constructor from Point test, Vector<int> V2(pt2)" << endl;
	Vector<int> V2(pt2);
	cout << "Cout test, both created Vectors: " << V1 << ", " << V2 << endl;
	cout << "operator== test, between both created Vectors: " << (V1 == V2) << endl;
	assert(V1 == V2);
	cout << "Magnitude test for V1, result expected: 5, result obtained: " << V1.magnitude() << endl;
	assert(V1.magnitude() == 5);
	cout << "Dot product test for V1 with Vector<int>(1,2), result expected: 11, result obtained:" << V1.dot(Vector<int>(1, 2)) << endl;
	assert(V1.dot(Vector<int>(1, 2)) == 11);
	cout << "Cross product test for V1 with Vector<int>(1,2), result expected: 2, result obtained:" << V1.cross(Vector<int>(1, 2)) << endl;
	assert(V1.cross(Vector<int>(1, 2)) == 2);
	cout << "operator+ test for V1 with Vector<int>(1,2), result expected: (4,6), result obtained:" << V1 + Vector<int>(1, 2) << endl;
	assert(V1 + Vector<int>(1, 2) == Vector<int>(4, 6));
	cout << "operator* test for V1 with 3, result expected: (9,12), result obtained:" << V1*3 << endl;
	assert(V1 * 3 == Vector<int>(9, 12));


	return 0;
}