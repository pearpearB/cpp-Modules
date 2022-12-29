#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact {
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		std::string _phoneNumber;
		std::string _darkestSecret;

	public:
		std::string getFirstName(void);
		std::string getLastName(void);
		std::string getNickname(void);
		std::string getPhoneNumber(void);
		std::string getDarkestSecret(void); 
		void setFirstName(std::string input);
		void setLastName(std::string input);
		void setNickname(std::string input);
		void setPhoneNumber(std::string input);
		void setDarkestSecret(std::string input);
};

#endif
