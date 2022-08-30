#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

# include <stack>

template < class T >
class MutantStack : public std::stack<T>
{
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator	const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator	reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;
	public:
		MutantStack() : std::stack<T>() {};
		MutantStack( MutantStack const & src ) : std::stack<T>(src) {};
		virtual ~MutantStack() {};
		MutantStack<T> &		operator=( MutantStack const & rhs )
		{
			if (*this != rhs)
				*this = new std::stack<T>(rhs);
			return (*this);
		};
		std::iterator<T> begin() {
			std::stack<T> s;
		};	
		std::iterator<T> end() {};	
};



#endif // MUTANT_STACK_HPP