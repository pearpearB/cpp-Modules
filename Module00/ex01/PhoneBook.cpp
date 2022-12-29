#include "PhoneBook.hpp"

void PhoneBook::setContactFeild(int field) {
	std::string input;

	while (true) {
		input.clear();
		std::getline(std::cin, input);
		if (std::cin.eof()) exit(0);
		if (!input.empty()) break ;
		std::cout << "Try again!:)" << std::endl;
	}
	if (field == FIRST_NAME) contact[idx].setFirstName(input);
	else if (field == LAST_NAME) contact[idx].setLastName(input);
	else if (field == NICKNAME) contact[idx].setNickname(input);
	else if (field == PHONE_NUMBER) contact[idx].setPhoneNumber(input);
	else if (field == DARKEST_SECRET) contact[idx].setDarkestSecret(input);
}

void printField(std::string field) {
	if (field.length() > 10) field = field.substr(0, 9) + ".";
	std::cout << std::setw(10) << field << "|";
}

void PhoneBook::printPhoneBook(void) {
	std::cout << "|";
	printField("Index"); printField("FirstName"); printField("LastName"); printField("Nickname");
	std::cout << std::endl;
	for (int i = 0; i < idx; i++) { // 8칸 까지 갔다가 앞으로 왔다면?!
		std::cout << std::setw(10) << i + 1 << "|";
		printField(contact[i].getFirstName()); printField(contact[i].getLastName()); printField(contact[i].getNickname());
		std::cout << std::endl;
	}
}

void PhoneBook::add(void) {
	std::cout << "1. First Name: ";
	PhoneBook::setContactFeild(FIRST_NAME);
	std::cout << "2. Last Name: ";
	PhoneBook::setContactFeild(LAST_NAME);
	std::cout << "3. Nickname: ";
	PhoneBook::setContactFeild(NICKNAME);
	std::cout << "4. Phone Number: ";
	PhoneBook::setContactFeild(PHONE_NUMBER);
	std::cout << "5. Darkest Secret: ";
	PhoneBook::setContactFeild(DARKEST_SECRET);
	if (idx == 7) full = true;
	idx = (idx + 1) % 8;
}

void PhoneBook::search(void) {
	int input;
	std::cout << "idx: " << idx << std::endl;
	if (!idx) {
		std::cout << "PhoneBook is empty" << std::endl;
		return ;
	}
	while (true) {
		std::cout << "Search for Index: " << "\n>";
		std::cin >> input;
		if (std::cin.eof()) exit(0);
		if (std::cin.fail() || input < 1 || input > 8 || (!full && input > idx)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 이거 뭔지 공부하기
			std::cout << "Search only the index in PhoneBook" << std::endl;
		}
		else break ;
	}
	std::cin.ignore(); // ??
	std::cout << "1. First Name: " << contact[input - 1].getFirstName() << std::endl
	<< "2. Last Name: " << contact[input - 1].getLastName() << std::endl
	<< "3. Nickname: " << contact[input - 1].getNickname() << std::endl
	<< "4. Phone Number: " << contact[input - 1].getPhoneNumber() << std::endl
	<< "5. Darkest Secret: " << contact[input - 1].getDarkestSecret() << std::endl;
}

PhoneBook::PhoneBook() {
	idx = 0, full = false;
}
