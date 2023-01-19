#include "AForm.hpp"

/* orthodox canonical AForm */
AForm::AForm(): _name("default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {
}

AForm::AForm(const std::string &name, const int gradeToSign, const int gradeToExecute): _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &src): _name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute) { }

AForm::~AForm() { }

AForm &AForm::operator=(const AForm &rhs) {
	if (this != &rhs)
		this->_isSigned = rhs._isSigned;
	return *this;
}

/* getter */
const std::string	&AForm::getName() const {
	return this->_name;
}

bool				AForm::getIsSigned() const {
	return this->_isSigned;
}

int					AForm::getGradeToSign() const {
	return this->_gradeToSign;
}

int					AForm::getGradeToExecute() const {
	return this->_gradeToExecute;
}

/* member function */
void	AForm::beSigned(Bureaucrat const &bureaucrat) {
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw GradeTooLowException();
	else
		this->_isSigned = true;
}

/* exception */
const char *AForm::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

const char *AForm::FormNotSignedException::what() const throw() {
	return "Form is not signed";
}

/* global function */
std::ostream &operator<<(std::ostream &out, const AForm &form) {
	out << "Form name: " << form.getName() << "\n" 
	<< "Form is signed: " << form.getIsSigned() << "\n" 
	<< "Form grade to sign: " << form.getGradeToSign() << "\n"
	<< "Form grade to execute: " << form.getGradeToExecute() << std::endl;
	return out;
}
