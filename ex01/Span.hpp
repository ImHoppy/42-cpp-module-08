#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <vector>
// TODO: plage d’itérateurs sur le contructor
class Span
{

	public:
		Span();
		Span( const Span & src );
		Span( const unsigned int & max );
		/*
		// the iterator constructor can also be used to construct from arrays:
		int myints[] = {16,2,77,29};
		std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
		// vector (InputIterator first, InputIterator last);

		Span( std::vector<int>::const_iterator );
		*/
		template<class InputIterator>
		Span(InputIterator first, InputIterator last) {
			_size = 0;
			_max = last - first;
			_lst.reserve(last - first);
			for (InputIterator it = first; it != last; ++it)
				addNumber(*it);
		};
		~Span();

		Span &		operator=( const Span & rhs );

		void		addNumber(int n);
		int			shortestSpan() const;
		int			longestSpan() const;

	private:
		unsigned int		_size;
		unsigned int		_max;
		std::vector<int>	_lst;
};


#endif /* SPAN_HPP */

