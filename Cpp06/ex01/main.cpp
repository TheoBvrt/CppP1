#include "Serializer.hpp"

int main(void) {
	Data data;

	data.id = 0;
	data.name = "Theo";
	data.value = 1;

	uintptr_t serializedPointer = Serializer::serialize(&data);

	Data* ptr = Serializer::deserialize(serializedPointer);

	std::cout << "original pointer : " << &data << std::endl;
	std::cout << "serialized pointer : " << serializedPointer << std::endl;
	std::cout << "deserialized pointer : " << ptr << std::endl;

	std::cout << "Data : " << ptr->name << std::endl;
	return (1);
}
