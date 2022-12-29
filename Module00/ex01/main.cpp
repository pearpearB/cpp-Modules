#include "PhoneBook.hpp"

int main(void) {
	std::string cmd;
	PhoneBook p;

	while (!std::cin.eof()) {
		std::cout << "Please enter: SEARCH | ADD | EXIT" << "\n>";
		std::getline(std::cin, cmd);
		if (!cmd.compare("EXIT")) break ;
		else if (!cmd.compare("ADD")) p.add();
		else if (!cmd.compare("SEARCH")) p.search();
		else continue ;
	}
	return (0);
}