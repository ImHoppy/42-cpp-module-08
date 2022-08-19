#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>

template<typename T>
bool	easyfind(T & container, const int & to_find)
{
	typename T::iterator it;
	it = std::find(container.begin(), container.end(), to_find);
	return (it != container.end());
}

#endif