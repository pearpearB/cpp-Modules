#include "Bureaucrat.hpp"

int main() {
	Bureaucrat max("max", 1);
	Bureaucrat min("min", 150);
	Bureaucrat normal("normal", 75);
	Bureaucrat excep("excep", 75);

	std::cout << "\n<---init--->" << std::endl;
	std::cout << normal << max << min << excep << std::endl;

	std::cout << "\n<---increment exception--->" << std::endl;
	try {
		max.incrementGrade();
		min.incrementGrade();
		excep.incrementGrade();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n<---increment result--->" << std::endl;
	std::cout << normal << max << min << excep << std::endl; // 왜 안바뀌죠?

	std::cout << "\n<---decrement exception--->" << std::endl;
	try {
		max.decrementGrade();
		min.decrementGrade();
		excep.decrementGrade();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n<---decrement result--->" << std::endl;
	std::cout << normal << max << min << excep << std::endl;

	return 0;
}