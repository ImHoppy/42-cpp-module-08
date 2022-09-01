#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

# include <stack>
# include <deque>

template < class T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
		typedef typename Container::iterator iterator;
		typedef typename Container::iterator const_iterator;
		
		MutantStack() : std::stack<T>() { };
		MutantStack( MutantStack const & src ) : std::stack<T>(src) {};
		virtual ~MutantStack() {};
		MutantStack<T> &		operator=( MutantStack const & rhs )
		{
			if (this != &rhs)
				std::stack<T, Container>::operator=(rhs);
			return (*this);
		};

		iterator	begin() {
			return this->c.begin();
		};
		iterator	end() {
			return this->c.end();
		};

		const_iterator	begin() const {
			return this->c.begin();
		};
		const_iterator	end() const {
			return this->c.end();
		};
};



#endif // MUTANT_STACK_HPP