#pragma once

namespace Geometry
{
	template<typename T = int>
	struct Point
	{
		T x,
		  y;
	};

	template<typename T = int>
	struct Line
	{
		T A,
		  B,
		  C;
	};

	template<typename T>
	struct Circle : Point<T>
	{
		T r;
	};

} // namespace Geometry