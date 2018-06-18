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

template<typename Iterator, typename Predicate = std::less<>>
void BubbleSort(Iterator first, Iterator last, Predicate predicate = Predicate())
{
	while (first < --last)
		for (auto i{ first }; i < last; ++i)
			if (predicate(*(i + 1), *i))
				std::iter_swap(i, i + 1);
}

/*
=====================================================================

Complexity = O(N^2)

Worst Case :
The number of comparisons in the body of the cycle is (N - 1) * N / 2.
The number of comparisons in the headers of cycles is (N - 1) * N / 2.
The total number of comparisons is (N - 1) * N.
The number of assignments in the cycle headers is (N - 1) * N / 2.
The number of exchanges is (N - 1) * N / 2.

Best case:
The number of comparisons in the body of the cycle is (N - 1) * N / 2.
The number of comparisons in the cycle headers is (N - 1) * N / 2.
The total number of comparisons is (N - 1) * N.
The number of exchanges is 0.

=====================================================================
*/