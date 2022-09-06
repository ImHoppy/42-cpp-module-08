#include <iostream>
#include <list>
#include <vector>
#include <set>
#include "easyfind.hpp"

#define PURPLE(A) "\033[35m" << A << "\033[0m"
#define GREEN(A) "\033[92m" << A << "\033[0m"

template<typename C, typename V>
inline void	test(const char* type, C container, V value)
{
	static int num = 0;
	++num;
	std::cout << PURPLE("#" << GREEN(num)) << " - easyfind( " << GREEN(type) << ", " << GREEN(value) << " )\t= " << std::boolalpha << GREEN(easyfind(container, value)) << std::endl;
}

int	main(void)
{
	std::list<int> a;
	a.push_back(1);
	a.push_back(42);
	std::cout << PURPLE("[1, 42]\n");
	test("list", a, 1);
	test("list", a, 21);
	test("list", a, 42);

	std::cout << std::endl;

	std::vector<int> b;
	b.push_back(-5);
	b.push_back(3);
	b.push_back(9);

	std::cout << PURPLE("[-5, 3, 9]\n");
	test("vector", b, 4);
	test("vector", b, -5);
	test("vector", b, 9);

	std::cout << std::endl;

	std::set<int> c;
	c.insert('I');
	c.insert('0');
	c.insert('v');

	std::cout << PURPLE("[I, 0, v]\n");
	test("set", c, 'I');
	test("set", c, '!');
	test("set", c, 'v');

	return 0;
}