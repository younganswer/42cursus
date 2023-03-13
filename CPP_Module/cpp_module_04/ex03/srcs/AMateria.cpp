#include "../incs/AMateria.hpp"

AMateria::AMateria(void): _type(std::string()), _xp(0), _equipped(false) {}
AMateria::AMateria(const std::string &type): _type(type), _xp(0), _equipped(false) {}
AMateria::AMateria(const AMateria &ref) { (*this) = ref; }
AMateria::~AMateria(void) {}

AMateria	&AMateria::operator=(const AMateria &ref) {
	if (this != &ref) {
		this->_type = ref._type;
		this->_xp = ref._xp;
		this->_equipped = ref._equipped;
	}
	return (*this);
}

// Getter
std::string			AMateria::getType(void) { return (this->_type); }
const std::string	&AMateria::getType(void) const { return (this->_type); }
unsigned int		AMateria::getXp(void) const { return (this->_xp); }
bool				AMateria::getEquipped(void) const { return (this->_equipped); }

// Setter
void				AMateria::setEquipped(bool equipped) { this->_equipped = equipped; }

// Utils
void				AMateria::use(ICharacter &target) { (void) target; this->_xp += 10; }