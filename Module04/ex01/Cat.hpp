#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain *_brain;
	
	public:
		Cat();
		Cat(const Cat &src);
		~Cat();
		Cat &operator=(const Cat &rhs);

		void makeSound() const;
};

#endif