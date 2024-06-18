#include <iostream>
#include <utility>
#include <cmath>
#include <stack>
#include "Utils.h"

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

		T x()
		{
			return coords.first;
		}

		T y()
		{
			return coords.second;
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
	std::pair<T, T> q_coords = q.get_coords();
	std::pair<T, T> r_coords = r.get_coords();

	int val = (q_coords.second - p_coords.second) * (r_coords.first - q_coords.first) - (q_coords.first - p_coords.first) * (r_coords.second - q_coords.second);

	if (val == 0)
		return 0; // colinear
	return (val > 0) ? 1 : 2; // clock or counterclock wise
}

std::vector<Punto<int>> randomPoints(int amount)
{
	std::vector<Punto<int>> result;
	for (int i = 0; i < amount; i++) {
		std::pair<int, int> rd_pair = get_random_pair(0, amount * 10);
		Punto<int> newPoint(rd_pair.first, rd_pair.second);
		result.push_back(newPoint);
	}
	return result;
}

std::vector<Punto<int>> semiRandomPoints(int inner_amount, int outer_amount)
{
	std::vector<Punto<int>> result = randomPoints(inner_amount);
	for (int i = 0; i < outer_amount; i++) {
		std::pair<int, int> rd_pair = get_random_pair(inner_amount * 11, (inner_amount + outer_amount) * 10);
		Punto<int> newPoint(rd_pair.first, rd_pair.second);
		result.push_back(newPoint);
	}
	return result;
}

template <typename T>
Punto<T> nextToTop(std::stack<Punto<T>>& S)
{
	Punto<T> p = S.top();
	S.pop();
	Punto<T> res = S.top();
	S.push(p);
	return res;
}

template <typename T>
std::vector<Punto<T>> stack_to_vector(std::stack<Punto<T>> stack)
{
	std::vector<Punto<T>> result;
	while (!stack.empty()) {
		result.push_back(stack.top());
		stack.pop();
	}
	std::reverse(result.begin(), result.end());
	return result;
}
template <typename T>
T distSq(Punto<T> lhs, Punto<T> rhs)
{
	return ((lhs.x() - rhs.x()) * (lhs.x() - rhs.x()) +
		(lhs.y() - rhs.y()) * (lhs.y() - rhs.y()));
}