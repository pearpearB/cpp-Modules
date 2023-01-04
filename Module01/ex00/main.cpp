#include "Zombie.hpp"

void makeHeapZ(void) {
	Zombie* newZ = newZombie("heapZ");
	newZ->announce();
	delete newZ; // delete로 할당 해제를 안 하면 메모리 누수가 발생함
}

int main(void) {
	Zombie defaultZ;
	defaultZ.announce();

	randomChump("stackZ");
	
	makeHeapZ();

	std::cout << "<-----check leaks----->" << std::endl;
	system("leaks zombie");

	return 0;
}

/*
defaultZ: BraiiiiiiinnnzzzZ...
stackZ: BraiiiiiiinnnzzzZ...
stackZ is dead									// stackZ를 선언한 randomChump()가 끝나면 소멸자가 불러짐
heapZ: BraiiiiiiinnnzzzZ...
heapZ is dead										// heapZ를 선언한 makeHeapZ()가 끝나면 소멸자가 불러짐
defaultZ is dead								// defaultZ를 선언한 main문이 끝나면 소멸자가 불러짐
*/
