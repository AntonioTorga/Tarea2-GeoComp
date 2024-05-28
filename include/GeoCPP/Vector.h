#include <iostream>
#include <cmath>
#include "Punto.h"

template <typename T>

class Vector {
	private:
		T x, y;

	public:
		Vector(T x_1, T y_1) : x(x_1), y(y_1) {}
		Vector(Punto<T>& point)
		{
			std::pair<T,T> point_coords = point.get_coords();
			x = point_coords.first;
			y = point_coords.second;
		}
		double magnitude()
		{
			return std::sqrt(x * x + y * y);
		}
		double dot(Vector<T> other) 
		{
			return this->x * other.x + this->y * other.y;
		}
		double cross(Vector<T> other) 
		{
			return this->x * other.y - other.x * this->y;
		}
		Vector<T> operator+(const Vector<T>& other)
		{
			return Vector(this->x + other.x, this->y + other.y);
		}
		Vector<T> operator*(T scalar)
		{
			return Vector(this->x * scalar, this->y * scalar);
		}
		bool operator==(const Vector<T>& other) 
		{
			return this->x == other.x && this->y == other.y;
		}
		std::pair<T,T> get_coords() const 
		{
			return make_pair(this->x,this->y);
		}
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& p)
{
	std::pair<T,T> p_coords = p.get_coords();
	os << "(" << p_coords.first << "," << p_coords.second << ")";
	return os;
}
