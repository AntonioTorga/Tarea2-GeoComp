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

//compare on polar angle
template <typename T>
bool compare(const Punto<T> p1, const Punto<T> p2, const Punto<T> p0)
{

	int o = orientation(p0, p1, p2);
	if (o == 0) return (distSq(p0, p2)) >= distSq(p0, p1) ? 0 : 1;
	return (o == 2) ? 0 : 1;
}

//convex hull
template <typename T>
Poligono<T> giftWrapping(std::vector<Punto<T>> cloud)
{
    int n = cloud.size();
    if (n < 3) return Poligono(cloud);

    int leftmost = 0;
    for (int i = 1; i < n; i++) {
        if (cloud[leftmost].x() < cloud[i].x()) leftmost = i;
    }

    int p = leftmost, q;
    std::vector<Punto<T>> result;
    do { // q es el punto propuesto para ser el proximo en el hull
        q = (p + 1) % n;
        for (int j = 0; j < n; j++) { // revisamos que todos los puntos j esten a la izq (ccw)
            if (orientation(cloud[p], cloud[j], cloud[q]) == 2) {
                q = j;
            }
        }
        result.push_back(cloud[q]);
        p = q;
    } while (p != leftmost);
    std::cout << "Size of convex hull: " << result.size() << std::endl;
    return Poligono(result);
}

template <typename T>
Poligono<T> grahamScan(std::vector<Punto<T>> cloud)
{
    int n = cloud.size();

    if (n < 3) {
        Poligono<T> result(cloud);
        return result;
    }

    int lowest = 0;
    for (int i = 1; i < n; i++) {
        if (cloud[lowest].y() > cloud[i].y()) {
            lowest = i;
        }
    }

    Punto<T> p = cloud[lowest];
    cloud.erase(cloud.begin() + lowest); //lowest is no longer in the cloud
    n--; //cloud is now n-1 in length

    auto compare_fn = [p](const Punto<int> p1, const Punto<int> p2) {
        return compare(p1, p2, p);
        };
    std::sort(cloud.begin(), cloud.end(), compare_fn); // we sort the cloud by polar angle on p

    std::stack<Punto<T>> stack;
    stack.push(p);
    stack.push(cloud[0]);

    for (int i = 1; i < n; i++) {
        while (stack.size() > 1 && orientation(stack.top(), nextToTop(stack), cloud[i]) != 2) {
            stack.pop();
        }
        stack.push(cloud[i]);
    }

    return Poligono<T>(stack_to_vector(stack));
}
