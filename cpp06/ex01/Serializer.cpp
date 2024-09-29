#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer& Serializer::operator=(const Serializer &src)
{
	if (this != &src)
		*this = src;
	return (*this);
}

Serializer::Serializer(Serializer const &src)
{
	*this = src;
}

Serializer::~Serializer(void) {}

/*
reinterpret_cast: This is a type of casting that allows you to reinterpret the bits of one type as 
another type. It’s used when you want to cast between fundamentally different types, such as 
between pointers or between pointers and integers. It doesn’t perform any safety checks or conversions; 
it simply reinterprets the memory as the new type.
*/

/*
The reinterpret_cast<uintptr_t>(ptr) is used when you need to convert a pointer (ptr) 
to an integer type, specifically to a type that can hold the value of a pointer, such as uintptr_t
*/
uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

/*
The expression reinterpret_cast<Data*>(raw) in C++ is used to cast an integer or a pointer (raw) to 
a pointer of type Data*. 
*/
Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}