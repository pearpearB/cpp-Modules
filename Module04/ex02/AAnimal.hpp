#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>

class AAnimal
{
	protected:
		std::string _type;

	public:
		AAnimal();
		AAnimal(const AAnimal &src);
		virtual ~AAnimal();
		AAnimal &operator=(const AAnimal &rhs);

		std::string getType() const;
		virtual void makeSound() const = 0; // ?!
};

#endif