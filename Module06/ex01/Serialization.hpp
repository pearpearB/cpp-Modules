#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

# include <iostream>

struct Data {
	std::string data;
};

class Serialization {
	public:
		Serialization();
		Serialization(Serialization const &src);
		~Serialization();
		Serialization &	operator=(Serialization const &	rhs);

		uintptr_t		*serialize(Data *ptr);
		Data			*deserialize(uintptr_t *raw);
};

#endif