#include <iostream>
#include <utility>
#include <cmath>

template <typename T>

class Punto {
	private:
		std::pair<T, T> coords;

	public:
		Punto(T x, T y) : coords(x, y) {};

		double distance(Punto<T>& b)
		{
			std::pair<T,T> b_coords = b.get_coords();

			double diff_x = coords.first - b_coords.first;
			double diff_y = coords.second - b_coords.second;
			return std::sqrt(diff_x*diff_x + diff_y*diff_y);
		}

		bool operator==(const Punto<T>& other)
		{
			std::pair<T,T> other_coords = other.get_coords();

			return this->coords.first == other_coords.first && this->coords.second == other_coords.second;
		}

		std::pair<T, T> get_coords() const
		{
			return coords;
		}

};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Punto<T>& p)
{
	std::pair<T,T> p_coords = p.get_coords();
	os << "(" << p_coords.first << "," << p_coords.second << ")";
	return os;
}

template <typename T>
int orientation(Punto<T> p, Punto<T> q, Punto<T> r)
{
	std::pair<T, T> p_coords = p.get_coords();
	std::pair<T, T> p_coords = p.get_coords();
	std::pair<T, T> p_coords = p.get_coords();

	int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

	if (val == 0)
		return 0; // colinear
	return (val > 0) ? 1 : 2; // clock or counterclock wise
}