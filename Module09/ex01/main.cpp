#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "[Usage]: ./RPN expression" << std::endl;
		exit (EXIT_FAILURE);
	}

	try {
		RPN rpn(argv[1]);
		rpn.execute();
	} catch (std::exception e) {
		std::cout << "Error" << std::endl;
	}
	
	return 0;
}