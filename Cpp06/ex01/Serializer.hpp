#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <stdint.h> 

struct Data {
	int	id;
	std::string name;
	double	value;
};

class Serializer {
	private:
		Serializer();
		Serializer(const Serializer& src);
		~Serializer();
		Serializer& operator=(const Serializer& other);

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif