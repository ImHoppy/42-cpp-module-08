#include "Span.hpp"

/* ------------------------------- CONSTRUCTOR ------------------------------ */

Span::Span() : _size(0), _max(0)
{
}

Span::Span( const Span & src )
{
	*this = src;
}

Span::Span( const unsigned int & max ) : _size(0), _max(max)
{
}


/* ------------------------------- DESTRUCTOR ------------------------------- */

Span::~Span()
{
}


/* -------------------------------- OVERLOAD -------------------------------- */

Span &				Span::operator=( Span const & rhs )
{
	if ( this != &rhs )
	{
		this->_size = rhs._size;
		this->_max = rhs._max;
		this->_lst = rhs._lst;
	}
	return *this;
}


/* -------------------------------- METHODS --------------------------------- */

void		Span::addNumber(int n)
{
	if (this->_size >= this->_max)
		throw std::exception();
	this->_lst.push_back(n);
//	this->_lst.insert(std::lower_bound(_lst.begin(), _lst.end(), n), n);
	++this->_size;
}

int			Span::shortestSpan() const
{
	std::vector<int>::const_iterator it;
	std::vector<int>::const_iterator it1;
	int j, i = 0;
	unsigned int n = (2^31) - 1;

	for (it = _lst.begin(); it != _lst.end(); ++it, ++i)
	{
		for (it1 = _lst.begin(), j = 0; it1 != _lst.end(); ++it1, ++j)
		{
			if (i != j && n > static_cast<unsigned int>(*it1-*it))
				n = static_cast<unsigned int>(*it1-*it);
		}
	}
	if (n == (2^31) - 1)
		throw std::exception();
	return n;
}
int			Span::longestSpan() const
{
	std::vector<int>::const_iterator it;
	std::vector<int>::const_iterator it1;
	int j, i = 0;
	int n = -1;

	for (it = _lst.begin(); it != _lst.end(); ++it, ++i)
	{
		for (it1 = _lst.begin(), j = 0; it1 != _lst.end(); ++it1, ++j)
		{
			if (i != j && n < *it1-*it)
				n = *it1-*it;
		}
	}
	if (n == -1)
		throw std::exception();
	return n;
}

/* -------------------------------- ACCESSOR -------------------------------- */


/* ************************************************************************** */

