#include <iostream>
#include "Span.hpp"
#include <ctime>
#include <cstdlib>

#define PURPLE(A) "\033[35m" << A << "\033[0m"
#define GREEN(A) "\033[92m" << A << "\033[0m"
#define RED(A) "\033[31m" << A << "\033[0m"

void	CreateBigSpan(void)
{
	srand(time(NULL));
	Span big(10000);
	for (int i = 0; i < 10000; ++i)
		big.addNumber(rand() % 10000);
	std::cout << PURPLE("Shortest span on 10000 numbers: ") << GREEN(big.shortestSpan()) << std::endl;
	std::cout << PURPLE("Longest span on 10000 numbers: ") << GREEN(big.longestSpan()) << std::endl;
}

int	main(void)
{
	Span err(1);
	err.addNumber(1);
	try {
		err.addNumber(1);
	}
	catch (const std::exception & e)
	{std::cerr << RED("Error on adding number above max: " << e.what()) << '\n';}
	try {
		err.shortestSpan();
	}
	catch (const std::exception & e)
	{std::cerr << RED("Error on getting shortest span without 2 number: " << e.what() ) << '\n';}
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << PURPLE("5 number shortest span: ") << GREEN(sp.shortestSpan()) << std::endl;
	std::cout << PURPLE("5 number longest span: ") << GREEN(sp.longestSpan()) << std::endl;
	sp = Span(5);
	sp.addNumber(3);
	sp.addNumber(-11);
	sp.addNumber(3);
	std::cout << PURPLE("3 number with negative shortest span: ") << GREEN(sp.shortestSpan()) << std::endl;
	std::cout << PURPLE("3 number with negative longest span: ") << GREEN(sp.longestSpan()) << std::endl;
	CreateBigSpan();
	return 0;
}
