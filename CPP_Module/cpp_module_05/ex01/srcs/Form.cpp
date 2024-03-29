#include "../incs/Form.hpp"
#include "../incs/Bureaucrat.hpp"
#include <iostream>

Form::Form(void): _name("Default"), _is_signed(false), _grade_to_sign(150), _grade_to_execute(150) {}
Form::Form(const std::string &name, int grade_to_sign, int grade_to_execute) throw(std::exception): _name(name), _is_signed(false), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute) {
	if (grade_to_sign < 1 || grade_to_execute < 1)
		throw Form::GradeTooHighException(_name);
	if (150 < grade_to_sign || 150 < grade_to_execute)
		throw Form::GradeTooLowException(_name);
}
Form::Form(const Form &ref): _name(ref._name), _is_signed(ref.getIsSigned()), _grade_to_sign(ref._grade_to_sign), _grade_to_execute(ref._grade_to_execute) {}
Form::~Form(void) {}

Form	&Form::operator=(const Form &rhs) {
	if (this != &rhs) {
		this->~Form();
		new (this) Form(rhs);
	}
	return (*this);
}

// Getter
const std::string	&Form::getName(void) const { return (this->_name); }
bool 				Form::getIsSigned(void) const { return (this->_is_signed); }
int 				Form::getGradeToSign(void) const { return (this->_grade_to_sign); }
int 				Form::getGradeToExecute(void) const { return (this->_grade_to_execute); }

// Util
void	Form::beSigned(const Bureaucrat &ref) throw(std::exception) {
	if (this->_grade_to_sign < ref.getGrade())
		throw Form::GradeTooLowException(ref.getName());
	if (this->_is_signed)
		throw Form::FormAlreadySignedException(this->_name);
	this->_is_signed = true;
}

// Exception: GradeTooHighException
Form::GradeTooHighException::GradeTooHighException(void): _msg("Grade is too high") {}
Form::GradeTooHighException::GradeTooHighException(const std::string &form) { this->_msg = form + " \'s grade is too high"; }
Form::GradeTooHighException::~GradeTooHighException(void) throw() {}
const char	*Form::GradeTooHighException::what(void) const throw() { return (this->_msg.c_str()); }

// Exception: GradeTooLowException
Form::GradeTooLowException::GradeTooLowException(void): _msg("Grade is too low") {}
Form::GradeTooLowException::GradeTooLowException(const std::string &form) { this->_msg = form + " \'s grade is too low"; }
Form::GradeTooLowException::~GradeTooLowException(void) throw() {}
const char	*Form::GradeTooLowException::what(void) const throw() { return (this->_msg.c_str()); }

// Exception: FormAlreadySignedException
Form::FormAlreadySignedException::FormAlreadySignedException(void): _msg("Form is already signed") {}
Form::FormAlreadySignedException::FormAlreadySignedException(const std::string &form) { this->_msg = form + " is already signed"; }
Form::FormAlreadySignedException::~FormAlreadySignedException(void) throw() {}
const char	*Form::FormAlreadySignedException::what(void) const throw() { return (this->_msg.c_str()); }

// operator overload
std::ostream	&operator<<(std::ostream &os, const Form &ref) {
	os << ref.getName() << " is " << (ref.getIsSigned() ? "signed" : "unsigned");
	os << ", grade to sign is " << ref.getGradeToSign();
	os << " and grade to execute is " << ref.getGradeToExecute();
	return (os);
}