#include <iostream>
#include "MutantStack.hpp"
#include <list>

#define PURPLE(A) "\033[35m" << A << "\033[0m"
#define GREEN(A) "\033[92m" << A << "\033[0m"
#define RED(A) "\033[31m" << A << "\033[0m"

void	test_list()
{
	std::list<int> mstack;
	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << PURPLE("TOP OF STACK: ") << GREEN(mstack.back()) << std::endl;
	mstack.pop_back();
	std::cout << PURPLE("SIZE: ") << GREEN(mstack.size()) << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	mstack.push_back(0);
	mstack.push_back(-42);

	std::list<int> copy = mstack;
	std::list<int>::iterator it = copy.begin();
	std::list<int>::iterator ite = copy.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

}

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << PURPLE("TOP OF STACK: ") << GREEN(mstack.top()) << std::endl;
	mstack.pop();
	std::cout << PURPLE("SIZE: ") << GREEN(mstack.size()) << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	mstack.push(-42);

	MutantStack<int> copy = mstack;
	MutantStack<int>::iterator it = copy.begin();
	MutantStack<int>::iterator ite = copy.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << PURPLE("Same test above but with std::list.") << std::endl;

	test_list();

	return 0;
}