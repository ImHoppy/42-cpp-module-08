#include <iostream>
#include "Span.hpp"
#include <ctime>
#include <cstdlib>

#define PURPLE(A) "\033[35m" << A << "\033[0m"
#define GREEN(A) "\033[92m" << A << "\033[0m"

void	CreateBigSpan(void)
{
	srand(time(NULL));
	Span big(10000);
	for (int i = 0; i < 10000; ++i)
		big.addNumber(rand() % 10000);
	std::cout << big.shortestSpan() << std::endl;
	std::cout << big.longestSpan() << std::endl;
}

int	main(void)
{
	Span err(1);
	err.addNumber(1);
	try {
		err.addNumber(1);
	}
	catch (const std::exception & e)
	{std::cerr << e.what() << '\n';}
	try {
		err.shortestSpan();
	}
	catch (const std::exception & e)
	{std::cerr << e.what() << '\n';}
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	sp = Span(5);
	sp.addNumber(3);
	sp.addNumber(11);
	sp.addNumber(3);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	CreateBigSpan();
	return 0;
}
