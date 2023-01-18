#include "RobotomyRequestForm.hpp"

/* orthodox canonical form */
RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), _target("default") { }

RobotomyRequestForm::RobotomyRequestForm(std::string const &target): AForm("RobotomyRequestForm", 72, 45), _target(target) { }

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src): AForm(src), _target(src._target) { }

RobotomyRequestForm::~RobotomyRequestForm() { }

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) {
	if (this != &rhs)
		AForm::operator=(rhs);
	return *this;
}

/* getter */
const std::string	&RobotomyRequestForm::getTarget() const {
	return this->_target;
}

/* member function */
void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	if (!this->getIsSigned())
		throw Form::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw Form::GradeTooLowException();
	else {
		srand(time(NULL));
		if (!rand() % 2)
			std::cout << this->_target << " robotomization failed" << std::endl;
		else {
			std::cout << "Drilling noises drilllllllllllllll≈≈≈≈≈≈≈≈≈≈≈≈≈!!!" << std::endl;
			std::cout << this->_target << " has been robotomized successfully" << std::endl;
		}
	}
}