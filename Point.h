#include <cmath>
#include <iostream>
#include <memory>
#include <algorithm>
#include <math.h>
#include <vector>

#define M_PIl          3.141592653589793238462643383279502884L

enum SHAPES { RECTANGLE = 0, SQUARE, NONE };

class Point
{
public:
	Point(double a, double b) :x(a), y(b) {};
	double x, y;
	double norm() const
	{
		return sqrt(x*x + y * y);
	}

};

inline double square(const double& x) { return x * x; }

inline double distance(const Point& p1, const Point &p2)
{
	return sqrt(square(p1.x - p2.x) + square(p1.y - p2.y));
}

inline std::ostream& operator<<(std::ostream& os, const Point& p)
{
	os << "(" << p.x << "," << p.y << ")";
	return os;
}
inline std::ostream& operator<<(std::ostream& os, const SHAPES& p)
{
	switch (p)
	{
	case RECTANGLE: os<<"RECTANGLE";break;
	case SQUARE: os << "SQUARE"; break;
	case NONE: os << "NONE"; break;
	default:os<< "UNKNOWN" ;
	}
	return os;
}


inline bool operator==(const Point& a, const Point& b) {
	return abs(a.x - b.x) < 1e-12 && abs(a.y - b.y) < 1e-12;
}

inline double operator*(const Point& p1, const Point &p2) {
	return p1.x*p2.x + p1.y*p2.y;
}

inline Point operator+(const Point& p1, const Point &p2) {
	return Point(p1.x + p2.x, p1.y + p2.y);
}

inline Point operator-(const Point& p1, const Point &p2) {
	return Point(p1.x - p2.x, p1.y - p2.y);
}

inline double angle(const Point& p1, const Point &p2)
{
	return acos(p1 * p2 / (p1.norm()*p2.norm()))*180.0 / M_PIl;
}


inline SHAPES WhatShape(std::vector<Point> points)
{
	if(points.size()!=4)
	{
		return NONE;
	}

	std::vector<Point> order;
	order.push_back(points[0]);
	points.erase(points.begin());

	for (int i = 0; i < points.size(); ++i)
	{
		std::vector<double> d;
		std::transform(points.begin(), points.end(), std::back_inserter(d), [&](const Point& p) {return distance(order.back(), p); });
		auto it = std::distance(d.begin(), std::min_element(d.begin(), d.end()));
		order.push_back(points[it]);
		points.erase(points.begin() + it);
	}
	order.push_back(points.back());

	//create the sides:
	std::vector<Point> edges;
	for (int i = 1; i < order.size(); ++i)
	{
		edges.push_back(order[i] - order[i - 1]);
	}
	edges.push_back(order[0] - order.back());
	bool isrectangular = true;

	//check angles:
	for (int i = 1; i < edges.size(); ++i)
	{
		double a = angle(edges[i], edges[i - 1]);
		if (abs(a - 90) > 1e-12)
		{
			isrectangular = false;
			break;
		}
	}

	bool isquared = isrectangular;
	//check if it is a square:
	double sideL = edges[0].norm();
	int i = 0;
	for (; isrectangular && i< edges.size(); ++i)
	{
		if (abs(sideL - edges[i].norm()) > 1e-12)
		{
			isquared = false;
			break;
		}
	}

	if (isquared)
		return SHAPES::SQUARE;

	if (isrectangular)
		return SHAPES::RECTANGLE;
	
	return SHAPES::NONE;
	
}