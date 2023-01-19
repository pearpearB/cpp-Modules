#include "Cat.hpp"
#include "Dog.hpp"

int main() {
	{
		Animal *animals[4] = {new Dog(), new Dog(), new Cat(), new Cat()};

		for (int i = 0; i < 4; i++)
			std::cout << animals[i]->getType() << std::endl;

		for (int i = 0; i < 4; i++)
			delete animals[i];
	}
	std::cout << std::endl;
	{
		Dog  *dog1 = new Dog();
		Dog dog2 = *dog1;
		delete dog1; // 얕은 복사면 같은 포인터를 해제해 터지게 되는데, 깊은 복사로 인해 해제가 안되어 터지지 않는다.
	}

	return 0;
}