#include "../incs/WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(void): WrongAnimal("WrongCat") {
	std::cout << "WrongCat default constructor called" << '\n';
	this->_brain = new Brain();	
}
WrongCat::WrongCat(const WrongCat &ref) {
	std::cout << "WrongCat copy constructor called" << '\n';
	(*this) = ref;
}
WrongCat::~WrongCat(void) {
	std::cout << "WrongCat destructor called" << '\n';
	delete this->_brain;
}

WrongCat	&WrongCat::operator=(const WrongCat &ref) {
	std::cout << "WrongCat copy assignation operator called" << '\n';
	if (this != &ref) {
		this->_type = ref._type;
		delete this->_brain;
		this->_brain = new Brain(*ref._brain);
	}
	return (*this);
}

// Util
void	WrongCat::makeSound(void) const { std::cout << "Meow~" << '\n'; }