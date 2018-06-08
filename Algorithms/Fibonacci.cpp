
typedef unsigned long long ull_t;

//====================================================================================================================================
//!
//! \brief   N-th Fibonacci number using the recursive algorithm
//!
//! \param   N  number  
//!
//! \return  N-th Fibonacci number
//!
//! \note    Be careful with large numbers!(overflow)
//!          		 
//!         T(N) = O(N)
//!         M(N) = O(1)
//!
//====================================================================================================================================

ull_t Fibonacci(ull_t N)
{
	if (!N)
		return (1ull);

	ull_t previous{ 1ull },
		  current{ 1ull };
	for (auto i{ 0ull }; i <= N; ++i)
	{
		auto tmp = current;

		current += previous;

		previous = tmp;
	}

	return (current);
}

//====================================================================================================================================
//!
//! \brief   N-th Fibonacci number using the recursive algorithm
//!
//! \param   N  number  
//!
//! \return  N-th Fibonacci number
//!
//! \note    Be careful with large numbers!(overflow)
//!          
//!			ATTENTION! 
//!         T(N) = Ω(φ^N)
//!         M(N) = O(N)
//!
//====================================================================================================================================

ull_t Fibonacci(ull_t N)
{
	if (!N || N == 1ull)
		return (1ull);

	return (Fibonacci(N - 1) + Fibonacci(N - 2));
}