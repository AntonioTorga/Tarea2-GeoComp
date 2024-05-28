#include <iostream>
#include <vector>
#include "Vector.h"

template <typename T>

class Poligono {
	private:
		std::vector < Punto<T> > vertices;
		int n;

	public:
		Poligono(std::vector < Punto<T> > vertex) : vertices(vertex), n(vertex.size()){}
		int get_n() const
		{
			return n;
		}
		std::vector<Punto<T>> get_vertices() const
		{
			return vertices;
		}
		Punto<T>& operator[](int i)
		{
			return vertices[i];
		}
		bool check_ccw()
		{
			T sum = 0;
			for (int i = 0; i < this->get_n() - 1; i++) {
				std::pair<T, T> i_coords = vertices[i].get_coords();
				std::pair<T, T> ipp_coords = vertices[i+1].get_coords();
				sum += (ipp_coords.first - i_coords.first) * (ipp_coords.second + i_coords.second);
			}
			return (sum > 0) ? false : true;
		}
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Poligono<T>& p)
{
	os << "[";
	std::vector<Punto<T>> vertices = p.get_vertices();
	for (int i = 0; i < p.get_n(); i++) {
		os << vertices[i];
		if (i != p.get_n() - 1) {
			os << ",";
		}
	}
	os << "]";
	return os;
}