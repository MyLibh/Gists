#include <utility> // std::swap

typedef long long ll_t;

//====================================================================================================================================
//!
//! \brief   Finds the greatest common divisor(GSD) of the integer numbers a and b
//!
//! \param   a  First number
//! \param   b  Second number
//!
//! \return  GSD
//!
//! \note    Be careful with large numbers!
//!
//====================================================================================================================================

ll_t GSD(ll_t a, ll_t b) noexcept
{
	if (!a)
		return b;
	if (!b)
		return a;

	ll_t shift{};
	for (; !((a | b) & 1); ++shift)
	{
		a >>= 1;
		b >>= 1;
	}

	while (!(a & 1))
		a >>= 1;

	do
	{
		while (!(b & 1))
			b >>= 1;

		if (a > b)
			std::swap(a, b);

		b -= a;
	} while (b);

	return (a << shift);
}