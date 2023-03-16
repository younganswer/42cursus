#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>

class Span {
	private:
		std::vector<int>	_vec;
		unsigned int		_size;
		Span(void);

	public:
		Span(unsigned int n);
		Span(const Span &ref);
		Span	&operator=(const Span &rhs);
		~Span(void);

		// Utils
		void	addNumber(int num);
		int		shortestSpan(void);
		int		longestSpan(void);
		
		bool			print(void);
		unsigned int	size(void);
		unsigned int	maxSize(void);

		// Exception: Duplicated
		class DuplicatedException: public std::exception {
			public:
				DuplicatedException(void);
				DuplicatedException(const DuplicatedException &ref);
				virtual ~DuplicatedException(void) throw();
				DuplicatedException	&operator=(const DuplicatedException &rhs);
				virtual const char* what() const throw();
		};

		// Exception: Not enough numbers
		class NotEnoughException: public std::exception {
			public:
				NotEnoughException(void);
				NotEnoughException(const NotEnoughException &ref);
				virtual ~NotEnoughException(void) throw();
				NotEnoughException	&operator=(const NotEnoughException &rhs);
				virtual const char* what() const throw();
		};
};

#endif