#include <stack>     // std::stack
#include <map>       // std::map
#include <cmath>     // std::powl, std::fmodl
#include <sstream>   // std::stringstream
#include <stdexcept> // std::out_of_range, std::invalid_argument

using ld_t = long double;

//====================================================================================================================================
//!
//! \brief   Evaluates reverse polish notation(RPN). You can check more about RPN:
//!          https://en.wikipedia.org/wiki/Reverse_Polish_notation
//!
//! \param   begin  Iterator to the begin
//! \param   end    Iterator to the end
//!
//! \return  result of RPN sequence
//!
//====================================================================================================================================

template<typename Iter>
ld_t EvaluateRPN(Iter begin, Iter end) noexcept(false)
{
	std::stack<ld_t> stackOfValues;
	auto pop_stack = [&]() -> ld_t
	{
		auto ret_val{ stackOfValues.top() };
		stackOfValues.pop();

		return ret_val;
	};

	static const std::map<std::string, ld_t (*) (ld_t, ld_t)> ops
	{
		{ "+", [] (ld_t a, ld_t b) { return (a + b); } },
		{ "-", [] (ld_t a, ld_t b) { return (a - b); } },
		{ "*", [] (ld_t a, ld_t b) { return (a * b); } },
		{ "/", [] (ld_t a, ld_t b) { return (a / b); } },
		{ "^", [] (ld_t a, ld_t b) { return std::powl(a, b); } },
		{ "%", [] (ld_t a, ld_t b) { return std::fmodl(a, b); } }
	};

	for (; begin != end; ++begin)
	{
		std::stringstream sstr{ *begin };

		if (ld_t val{}; sstr >> val)
			stackOfValues.push(val);
		else
		{
			const auto l{ pop_stack() };
			const auto r{ pop_stack() };

			try
			{
				const auto &op(ops.at(*begin));
				stackOfValues.push(op(l, r));
			}
			catch (const std::out_of_range&)
			{
				throw std::invalid_argument(begin->c_str());
			}
		}
	}

	return stackOfValues.top();
} 
