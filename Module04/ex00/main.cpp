#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

void testLeaks() {
	{
		std::cout << "\n<-----test each class----->" << std::endl;
		const Animal* animal = new Animal();
		const Cat* cat = new Cat();
		const Dog* dog = new Dog();

		std::cout << animal->getType() << std::endl;
		std::cout << cat->getType() << std::endl;
		std::cout << dog->getType() << std::endl;
		animal->makeSound();
		cat->makeSound();
		dog->makeSound();

		delete animal;
		delete cat;
		delete dog;
	}
	{
		std::cout << "\n<-----test parent class----->" << std::endl;
		const Animal* animal = new Animal();

		delete animal;       // 자식 클래스를 가리키기 전에, 릭을 방지할 수 있도록 delete 해주기!

		animal = new Cat();  // 부모 클래스는 자식 클래스를 가리킬 수 있다.
		animal->makeSound();

		delete animal;

		animal = new Dog();
		animal->makeSound();
		
		delete animal;
	}
	{
		std::cout << "\n<-----test const----->" << std::endl;
		const Animal* animal = new Animal();
		const Animal* cat = new Cat();

		*animal = *cat; // error: cannot assign to variable 'animal' with const-qualified type 'const Animal *const'
	}
}

int main() {

	testLeaks();
	system("leaks animal");

	{
		std::cout << "\n<-----test not use virtual----->" << std::endl;
		const WrongAnimal* wrong = new WrongAnimal();
		const WrongAnimal* wrongCat = new WrongCat();

		wrong->makeSound();
		wrongCat->makeSound();

		delete wrong;
		delete wrongCat;

	}

	return 0;
}