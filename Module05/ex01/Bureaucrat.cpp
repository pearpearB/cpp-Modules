#include "Bureaucrat.hpp"

/* orthodox canonical form */
Bureaucrat::Bureaucrat(): _name("default"), _grade(150) {
}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name), _grade(grade) {
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &src): _name(src._name), _grade(src._grade) { }

Bureaucrat::~Bureaucrat() { }

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs) {
	if (this != &rhs)
		this->_grade = rhs._grade;
	return *this;
}

/* getter */
const std::string	&Bureaucrat::getName() const {
	return this->_name;
}

int					Bureaucrat::getGrade() const {
	return this->_grade;
}

/* member function */
void	Bureaucrat::incrementGrade() {
	if (this->_grade == 1)
		throw GradeTooHighException();
	else
		--this->_grade;
}

void	Bureaucrat::decrementGrade() {
	if (this->_grade == 150)
		throw GradeTooLowException();
	else
		++this->_grade;
}

void	Bureaucrat::signForm(Form &form) {
	try {
		form.beSigned(*this); // 여기서 예외가 발생하면 아래 문장은 실행되지 않는다.
		std::cout << this->_name << " signs " << form.getName() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << this->_name << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl; // 예외 메시지를 받아 출력한다.
	}
}

/* exception */
const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

/* global function */
std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs) {
	return out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << "." << std::endl;
}