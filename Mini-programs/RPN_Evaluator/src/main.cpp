#include <iostream> // std::ios_base::sync_with_stdio, std::cout
#include <iterator> // std::istream_iterator

#include "RPN_Evaluator.hpp"

int main()
{
	std::ios_base::sync_with_stdio(false);

	std::stringstream sstr{ "3 2 1 + * 2 /" };
	try
	{
		std::cout << EvaluateRPN(std::istream_iterator<std::string>(sstr), {}) << std::endl;
	}
	catch (const std::invalid_argument &e)
	{
		std::cout << "Invalid operator: " << e.what() << std::endl;
	}

	system("pause");
	return 0;
}