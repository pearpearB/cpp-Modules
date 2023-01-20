#include "Form.hpp"

/* orthodox canonical form */
Form::Form(): _name("default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {
}

Form::Form(const std::string &name, const int gradeToSign, const int gradeToExecute): _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &src): _name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute) { }

Form::~Form() { }

Form &Form::operator=(const Form &rhs) {
	if (this != &rhs)
		this->_isSigned = rhs._isSigned;
	return *this;
}

/* getter */
const std::string	&Form::getName() const {
	return this->_name;
}

bool				Form::getIsSigned() const {
	return this->_isSigned;
}

int					Form::getGradeToSign() const {
	return this->_gradeToSign;
}

int					Form::getGradeToExecute() const {
	return this->_gradeToExecute;
}

/* member function */
void	Form::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw GradeTooLowException();
	else
		this->_isSigned = true;
}

/* exception */
const char *Form::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

/* global function */
std::ostream &operator<<(std::ostream &out, const Form &form) {
	out << "Form name: " << form.getName() << "\n" 
	<< "Form is signed: " << form.getIsSigned() << "\n" 
	<< "Form grade to sign: " << form.getGradeToSign() << "\n"
	<< "Form grade to execute: " << form.getGradeToExecute() << std::endl;
	return out;
}