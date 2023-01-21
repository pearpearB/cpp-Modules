#include "Serialization.hpp"

void testLeak()
{
	Data			*ptr = new Data();
	Serialization	serialization;

	ptr->data = "Hello World!";
	std::cout << "before serialize: " << ptr << std::endl;
	std::cout << "data: " << ptr->data << std::endl;

	uintptr_t	*raw = serialization.serialize(ptr);
	std::cout << "\nafter serialize: " << raw << std::endl;

	ptr = serialization.deserialize(raw);
	std::cout << "\nafter deserialize: " << ptr << std::endl;
	// std::cout << "static cast: " << static_cast<Data*>(raw) << std::endl; 
	// static_cast from 'uintptr_t *' (aka 'unsigned long *') to 'Data *' is not allowed
	
	std::cout << "\ndata: " << ptr->data << std::endl;

	delete ptr;
}

void test()
{
	int value = 42;
	int	*ptr1 = &value;
	std::cout << "before serialize: " << ptr1 << ", " << *ptr1 << std::endl;

	std::cout << "\n===== int -> double, char =====" << std::endl;

	double *ptr2 = reinterpret_cast<double*>(ptr1);
	std::cout << "after serialize: " << ptr2 <<  ", " << *ptr2 << std::endl;
	
	char *ptr3 = reinterpret_cast<char*>(ptr2);
	std::cout << "after serialize: " << (void *)ptr3 <<  ", " << *ptr3 << std::endl; 
	// outsteam이 오버로드되기 때문에 포인터 주소 출력시 (void *)로 캐스팅해야함

	std::cout << "\n===== double, char -> int =====" << std::endl;
	
	int *ptr4 = reinterpret_cast<int*>(ptr2);
	std::cout << "after deserialize: " << ptr4 << ", " << *ptr4 << std::endl;

	int *ptr5 = reinterpret_cast<int*>(ptr3);
	std::cout << "after deserialize: " << ptr5 << ", " << *ptr5 << std::endl;
}

void test2()
{
	int value = 42;
	int	*ptr1 = &value;
	std::cout << "before serialize: " << &ptr1 << ", " << *ptr1 << std::endl; 
	
	char *ptr2 = reinterpret_cast<char*>(ptr1);
	std::cout << "after serialize: " << &ptr2 <<  ", " << *ptr2 << std::endl;

	int *ptr3 = reinterpret_cast<int*>(ptr2);
	std::cout << "after deserialize: " << &ptr3 << ", " << *ptr3 << std::endl;
	// 주소값을 출력하면 -8비트씩 당겨져 출력됨, 왜? 
}

int main()
{
	// testLeak();
	test();
	test2();

	// system("leaks serialization");

	return 0;
}