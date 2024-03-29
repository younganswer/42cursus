#include "../incs/MateriaSource.hpp"

MateriaSource::MateriaSource(void): _count(0) {
	for (int i = 0; i < 4; i++) {
		this->_materia[i] = NULL;
	}
}
MateriaSource::MateriaSource(const MateriaSource &ref): _count(ref._count) {
	for (int i=0; i<4; i++) {
		if (ref._materia[i]) {
			this->_materia[i] = ref._materia[i]->clone();
		}
	}
}
MateriaSource::~MateriaSource(void) {
	for (int i=0; i<4; i++) {
		if (this->_materia[i] != NULL) {
			delete this->_materia[i];
		}
	}
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &rhs) {
	if (this != &rhs) {
		this->~MateriaSource();
		new (this) MateriaSource(rhs);
	}
	return (*this);
}

// Utils
void	MateriaSource::learnMateria(AMateria *mat) {
	if (4 <= this->_count) {
		return;
	}
	for (int i=0; i<this->_count; i++) {
		if (this->_materia[i]->getType() == mat->getType()) {
			return;
		}
	}
	this->_materia[this->_count++] = mat;
}

AMateria	*MateriaSource::createMateria(const std::string &type) const {
	for (int i=0; i<_count; i++) {
		if (this->_materia[i]->getType() == type) {
			return (this->_materia[i]->clone());
		}
	}
	return (NULL);
}