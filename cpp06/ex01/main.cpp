#include "Serializer.hpp"

int main(void)
{

	Data *data = new Data;
	data->name = "Trajka";
    data->lastName = "Menkovic";
	data->age = 3;
	data->adress = "Ohratie 10";
    data->phoneNumber = "no phone";
    data->weight = 3.8;
    data->height = 20.0;
	data->next = nullptr;

	uintptr_t raw = Serializer::serialize(data);
	Data *serialized = Serializer::deserialize(raw);

	std::cout << serialized->name << std::endl;
    std::cout << serialized->lastName << std::endl;
	std::cout << serialized->age << std::endl;
    std::cout << serialized->adress << std::endl;
	std::cout << serialized->phoneNumber << std::endl;
    std::cout << serialized->weight << std::endl;
    std::cout << serialized->height << std::endl;
    std::cout << serialized->next << std::endl;

	delete data;
	return (0);
}