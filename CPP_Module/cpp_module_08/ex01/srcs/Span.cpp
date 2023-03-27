#include "../incs/Span.hpp"
#include <iostream>

Span::Span(void) {}
Span::~Span(void) {}
Span::Span(unsigned int n): _size(n) {}
Span::Span(const Span &ref): _size(ref._size) {
	for (size_t i=0; i<ref._vec.size(); i++) {
		this->_vec.push_back(ref._vec[i]);
	}
}

Span	&Span::operator=(const Span &rhs) {
	if (this != &rhs) {
		this->~Span();
		new (this) Span(rhs);
	}
	return (*this);
}

void	Span::addNumber(int num) {
	if (this->_size <= this->_vec.size()) {
		throw std::length_error("Span size exceed maximum allowed size");
	}

	if (this->_vec.size() == 0) {
		this->_vec.push_back(num);
		return;
	}

	std::vector<int>::iterator	it = this->_vec.begin();
	while (it != this->_vec.end()) {
		if (*it == num) {
			throw DuplicatedException();
		}
		if (*it > num) {
			break;
		}
		it++;
	}
	this->_vec.insert(it, num);
}

int		Span::shortestSpan(void) const {
	if (this->_vec.size() <= 1) {
		throw NotEnoughException();
	}
	
	int ret = 2147483647;
	for (size_t i=0; i<this->_vec.size()-1; i++) {
		int	span = this->_vec[i+1] - this->_vec[i];
		if (span < ret) {
			ret = span;
		}
	}
	return (ret);
}

int		Span::longestSpan(void) const {
	if (this->_vec.size() <= 1) {
		throw NotEnoughException();
	}
	
	return (this->_vec[this->_vec.size()-1] - this->_vec[0]);
}

bool	Span::print(void) const {
	for (size_t i=0; i<this->_vec.size(); i++) {
		std::cout << this->_vec[i] << ' ';
	}
	std::cout << '\n';
	return (true);
}

unsigned int	Span::size(void) const {
	return (this->_vec.size());
}

unsigned int	Span::maxSize(void) const {
	return (this->_size);
}

// Exception: Duplicated
Span::DuplicatedException::DuplicatedException(void) {}
Span::DuplicatedException::~DuplicatedException(void) throw() {}
const char	*Span::DuplicatedException::what() const throw() {
	return ("Duplicated number");
}

// Exception: Not enough numbers
Span::NotEnoughException::NotEnoughException(void) {}
Span::NotEnoughException::~NotEnoughException(void) throw() {}
const char	*Span::NotEnoughException::what() const throw() {
	return ("Not enough numbers");
}