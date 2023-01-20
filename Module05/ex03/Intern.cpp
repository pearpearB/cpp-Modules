#include "Intern.hpp"

/* orthodox canonical form */
Intern::Intern() { }

Intern::Intern(const Intern &src) {
	*this = src;
}

Intern::~Intern() { }

Intern &Intern::operator=(const Intern &rhs) {
	if (this != &rhs) {
		;
	}
	return *this;
}

/* member function */
AForm *Intern::findForm(std::string const &formName, std::string const &target) {
	const std::string	formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm				*forms[3] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)};
	
	for (int i = 0; i < 3; i++) {
		if (!formName.compare(formNames[i])) {
			return forms[i];
		}
	}
	throw FormNotFoundException();
	return NULL;
}

AForm *Intern::makeForm(std::string const &formName, std::string const &target) {
	AForm *form;
	try {
		form = findForm(formName, target);
		std::cout << "Intern creates " << form->getName() << std::endl;
		return form;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return NULL;
}

/* exception */
const char *Intern::FormNotFoundException::what() const throw() {
	return "Form not found";
}