#include <algorithm>

/*
=====================================================================

Complexity = O(n ^ 2)

Worst Case :
The number of comparisons in the body of the cycle is(N - 1) * N / 2.
The number of comparisons in the headers of cycles is(N - 1) * N / 2.
The total number of comparisons is(N - 1) * N.
The number of assignments in the cycle headers is(N - 1) * N / 2.
The number of exchanges is(N - 1) * N / 2.

Best case:
The number of comparisons in the body of the cycle is(N - 1) * N / 2.
The number of comparisons in the cycle headers is(N - 1) * N / 2.
The total number of comparisons is(N - 1) * N.
The number of exchanges is 0.

=====================================================================
*/

template<typename Iter, typename Pred = std::less<>>
void BubbleSort(Iter first, Iter last, Pred p = Pred())
{
	while (first < --last)
		for (auto i{ first }; i < last; ++i)
			if (p(*(i + 1), *i))
				std::iter_swap(i, i + 1);
}