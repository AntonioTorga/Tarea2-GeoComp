#ifndef PUNTO_H
#define PUNTO_H

#include <iostream>
#include <utility>
#include <cmath>
#include <stack>
#include <algorithm>
#include <vector>
#include "Utils.h"


template <typename T>
class Punto {
	private:
		std::pair<T, T> coords;

	public:
		Punto(T x, T y) {
			coords = std::make_pair(x, y);
		};

		double distance(Punto<T>& b)
		{
			std::pair<T,T> b_coords = b.get_coords();

			double diff_x = coords.first - b_coords.first;
			double diff_y = coords.second - b_coords.second;
			return std::sqrt(diff_x*diff_x + diff_y*diff_y);
		}

		bool operator==(const Punto<T>& other) const
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
	T val = (q.y() - p.y()) * (r.x() - q.x() )
		- (q.x() - p.x()) * (r.y() - q.y());
	if (val == 0)
		return 0; // colinear
	return (val > 0) ? 1 : 2; // clock or counterclock wise
}

inline std::vector<Punto<long long>> createConvexPolygon(long long amount, long long space) {
	double pi = 2 * acos(0.0);

	double angle_df = 2*pi / amount, init_angle = (amount%2==0)? -angle_df / 2: pi/2;
	
	std::vector<Punto<long long>> result;
	for (int i = 0; i < amount; i++) {
		double curr_angle = init_angle + angle_df * i;
		Punto<long long> new_point(cos(curr_angle)*space, sin(curr_angle)*space);
		curr_angle += angle_df;
		result.push_back(new_point);
	}
	return result;
}

inline std::vector<Punto<long long>> randomPoints(long long amount, long long space)
{
	std::vector<Punto<long long>> result;
	// this is because if we have amount > 4*space*space the will go on forever
	// because it will not be able to find a space for the new dot. But, to prevent 
	// large computation time we'll restrict it  to 2*space*space
	
	if (amount > 2 * space * space) return result;
	while (result.size()<amount) {
		std::pair<long long, long long> rd_pair = get_random_pair(0, space);
		Punto<long long> newPoint(rd_pair.first, rd_pair.second);
		//if (std::find(result.begin(), result.end(), newPoint) == result.end())
		result.push_back(newPoint);	
	}
	return result;
}

inline std::vector<Punto<long long>> semiRandomPoints(long long amount, double outter_percentage, long long space)
{
	std::vector<Punto<long long>> result;

	if (outter_percentage > 100) return result;

	long long outter_amount = ceil(amount * (outter_percentage / 100.0));
	long long inner_amount = amount - outter_amount;
	std::vector<Punto<long long>> inner_points = randomPoints(inner_amount, space);
	std::vector<Punto<long long>> outter_points = createConvexPolygon(outter_amount, space*2);

	result.insert(result.end(), inner_points.begin(), inner_points.end());
	result.insert(result.end(), outter_points.begin(), outter_points.end());

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

#endif // PUNTO_H
