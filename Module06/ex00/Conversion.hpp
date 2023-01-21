#ifndef CONVERSION_HPP
# define CONVERSION_HPP

# include <iostream>
# include <iomanip>

class Conversion {
	private:
		std::string		_param;
		double			_value;

	public:
		Conversion();
		Conversion(std::string param);
		Conversion(Conversion const & src);
		~Conversion();
		Conversion &	operator=(Conversion const & rhs);

		void			convertToChar(void);
		void			convertToInt(void);
		void			convertToFloat(void);
		void			convertToDouble(void);

		class ImpossibleException : public std::exception {
			const char* what() const throw();
		};

};

std::ostream &	operator<<(std::ostream & o, Conversion const & rhs);

#endif