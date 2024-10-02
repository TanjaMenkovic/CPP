/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:11:37 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/10/02 15:40:47 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
	std::cout << std::endl;
	std::cout << "\033[34m[Constructing]\n\033[0m" << std::endl;
	const Animal	*meta[10];
	for (int i = 0; i < 10; i++)
	{
		if (i % 2)
		{
			meta[i] = new Cat();
			if (meta[i] == NULL)
			{
				perror("Cat couldn't be allocated!");
				std::cerr << "Exiting process now";
				exit(1);
			}
		}
		else
		{
			meta[i] = new Dog();
			if (meta[i] == NULL)
			{
				perror("Dog couldn't be allocated!");
				std::cerr << "Exiting process now";
				exit(1);
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	std::cout << "\033[34m[Testing]\n\033[0m" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << std::endl;
		std::cout << "Animal _type: " << meta[i]->getType() << std::endl;
		meta[i]->makeSound();
		std::cout << std::endl;
	}
	std::cout << std::endl;

	std::cout << "\033[34m[Deconstructing]\n\033[0m" << std::endl;
	for (int i = 0; i < 10; i++)
		delete(meta[i]);

	std::cout << std::endl << std::endl;
	std::cout << "\033[38;5;213m[showing that the copy constructor creates a deep copy]" << std::endl;
	std::cout << std::endl;

	std::cout << "\033[34m[Constructing]\n\033[0m" << std::endl;
	Dog *a = new Dog();
	// Cat *a = new Cat();
	if (a == NULL)
	{
		perror("Allocation failed");
		std::cerr << "Exiting the process now." << std::endl;
		exit(1);
	}

	a->setIdea(0, "I need to poop your entire house!");
	a->setIdea(1, "Give me your whole food!!!");
	a->setIdea(2, "Let's go out! Let's go out!!!");
	a->setIdea(3, "Wake up now!");
	a->setIdea(4, "LEt's play! Let's play!!!");
	std::cout << "\nIncorrect input: " << std::endl;
	a->setIdea(200, "no idea");
	std::cout << std::endl;

	Dog *b = new Dog(*a);
	// Cat *b = new Cat(*a);
	if (b == NULL)
	{
		perror("Allocation failed");
		std::cerr << "Exiting the process now." << std::endl;
		exit(1);
	}
	std::cout << std::endl;

	std::cout << "\033[34m[Testing a]\n\033[0m" << std::endl;
	std::cout << "The " << a->getType() << " a has the following ideas: " << std::endl;
	a->getIdeas();
	std::cout << std::endl;

	std::cout << "\033[34m[Deconstructing a]\n\033[0m" << std::endl;
	delete(a);
	std::cout << std::endl;

	std::cout << "\033[34m[Testing b]\n\033[0m" << std::endl;
	std::cout << "The " << b->getType() << " b has the following ideas: " << std::endl;
	b->getIdeas();
	std::cout << std::endl;

	std::cout << "\033[34m[Deconstructing b]\n\033[0m" << std::endl;
	delete(b);

	return (0);
}