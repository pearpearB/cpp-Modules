#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "./Contact.hpp"
# include <iostream>
# include <iomanip>

enum e_field {
	FIRST_NAME,
	LAST_NAME,
	NICKNAME,
	PHONE_NUMBER,
	DARKEST_SECRET
};

class PhoneBook {
	private:
		Contact contact[8];
		int 	idx;
		bool	full;
		int 	printPhoneBook(void);
		void 	setContactFeild(int field);

	public:
		void	add(void);
		void	search(void);
		PhoneBook();
};

#endif