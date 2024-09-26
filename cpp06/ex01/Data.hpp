#pragma once

#include <iostream>

typedef struct	Data
{
	std::string name;
    std::string lastName;
	int			age;
	std::string	adress;
    std::string phoneNumber;
    float       weight;
    float       height;
    Data        *next;
}   Data;