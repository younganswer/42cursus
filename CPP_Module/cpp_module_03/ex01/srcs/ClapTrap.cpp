#include "../incs/ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(void): _name(std::string()), _hit_points(10), _energy_points(10), _attack_damage(0) {
	std::cout << "Default constructor of CL4P-TP is called" << '\n';
}
ClapTrap::ClapTrap(const std::string &name): _name(name), _hit_points(10), _energy_points(10), _attack_damage(0) {
	std::cout << "Const std::string reference constructor of CL4P-TP is called" << '\n';
}
ClapTrap::ClapTrap(const ClapTrap &ref): _name(ref._name), _hit_points(ref._hit_points), _energy_points(ref._energy_points), _attack_damage(ref._attack_damage) {
	std::cout << "Copy constructor of CL4P-TP is called" << '\n';
}
ClapTrap::~ClapTrap(void) {
	std::cout << "Destructor of CL4P-TP is called" << '\n';
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &rhs) {
	std::cout << "Copy assignment operator of CL4P-TP is called" << '\n';
	if (this != &rhs) {
		this->~ClapTrap();
		new (this) ClapTrap(rhs);
	}
	return (*this);
}

// Utils
void	ClapTrap::attack(const std::string &target) {
	if (this->_hit_points == 0) {
		std::cout << "CL4P-TP [" << this->_name << "] is run out of its hit points" << '\n';
	} else if (this->_energy_points == 0) {
		std::cout << "CL4P-TP [" << this->_name << "] is run out of its energy points" << '\n';
	} else {
		std::cout << "CL4P-TP [" << this->_name << "] attacks [" << target << "], causing [" << this->_attack_damage << "] points of damage!" << '\n';
		this->_energy_points--;
	}
	return;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hit_points == 0) {
		std::cout << "CL4P-TP [" << this->_name << "] is run out of its hit points" << '\n';
	} else if (this->_hit_points <= amount) {
		std::cout << "CL4P-TP [" << this->_name << "] took [" <<  this->_hit_points << "] damage!" << '\n';
		this->_hit_points = 0;
		std::cout << "CL4P-TP [" << this->_name << "] is run out of its hit points" << '\n';
	} else {
		std::cout << "CL4P-TP [" << this->_name << "] took [" <<  amount << "] damage!" << '\n';
		this->_hit_points -= amount;
		std::cout << "CL4P-TP [" << this->_name << "] has [" << this->_hit_points << "] hit points left" << '\n';
	}
	return;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hit_points == 0) {
		std::cout << "CL4P-TP [" << this->_name << "] is run out of its hit points" << '\n';
	} else if (this->_energy_points == 0) {
		std::cout << "CL4P-TP [" << this->_name << "] is run out of its energy points" << '\n';
	} else {
		std::cout << "CL4P-TP [" << this->_name << "] is repaired: Restore [" << amount << "] hit points" << '\n';
		this->_hit_points += amount;
		std::cout << "CL4P-TP [" << this->_name << "] has [" << this->_hit_points << "] hit points now" << '\n';
		this->_energy_points--;
	}
	return;
}