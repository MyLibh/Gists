#include <utility> // std::iter_swap
#include <xstddef> // std::less

//====================================================================================================================================
//!
//! \brief  Sorts elements in [first, last) using 'predicate'
//!
//! \param  first      Iterator to the begin of container
//! \param  last       Iterator to the end of container
//! \param  predicate  Predicate to compare for sorting
//!
//! \throw  ???
//!
//! \note   Uses std::less<> as default predicate
//!
//!          T(N) = O(N^2)
//!			 M(N) = O(1)
//!
//====================================================================================================================================

template <typename Iterator, typename Predicate = std::less<>>
void InsertionSort(Iterator first, Iterator last, Predicate pred = Predicate())
{
	for (Iterator i{ first + 1 }; i != last; ++i)
		for (Iterator j{ i }; j != first && pred(*j, *(j - 1)); --j)
			std::iter_swap(j - 1, j);
}