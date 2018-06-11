#include <utility> // std::pair
#include <vector>  // std::vector
#include <cmath>   // std::fabs, std::sqrt

#include "Geometry.hpp"
	

typedef long double ld_t;

enum class IntersectionType
{
	NONE,
	TOUCHING,
	INTERSECTION
};

template<typename T> // The intersection of a circle and a line
std::pair<IntersectionType, std::vector<Geometry::Point<T>>> GetIntersection(const Geometry::Circle<T> &crCircle, const Geometry::Line<T> &crLine, const ld_t EPS = 0.001)
{
	Geometry::Line<T> line{ crLine.A, crLine.B, crLine.A * crCircle.x + crLine.B * crCircle.y + crLine.C };
	
	auto tmp = line.A * line.A + line.B * line.B;
	Geometry::Point<T> point{ -line.A * line.C / tmp, -line.B * line.C / tmp};

	auto R2 = crCircle.r * crCircle.r;
	auto C2 = line.C * line.C;
	if (auto R2tmp = R2 * tmp; C2 > R2tmp + EPS)
		return (std::make_pair(IntersectionType::NONE, {}));
	else if (std::fabs(C2 - R2tmp) < EPS)
		return (std::make_pair(IntersectionType::TOUCHING, { point }));
	else
	{
		auto d = R2 - C2 / tmp;
		auto sqrt = std::sqrt(d / tmp);

		return (std::make_pair(IntersectionType::TOUCHING, { { point.x + line.B * sqrt + crCircle.x, point.y - line.A * sqrt + crCircle.y }, 
			                                                 { point.x - line.B * sqrt + crCircle.x, point.y + line.A * sqrt + crCircle.y } }));
	}
}