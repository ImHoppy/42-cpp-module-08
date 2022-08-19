#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <vector>

class Span
{

	public:

		Span();
		Span( const Span & src );
		Span( const unsigned int & max );
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

