/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:11:37 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/10/02 15:44:47 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main() {
    // Animal animal; // Error: Cannot instantiate abstract class
    std::cout << std::endl;
	std::cout << "\033[34m[creating them]\033[0m" << std::endl;
	Cat cat;
    Dog dog;

    Animal* animal1 = &cat;
    Animal* animal2 = &dog;
	
	std::cout << std::endl;
	std::cout << "\033[34m[sound]\033[0m" << std::endl;
    animal1->makeSound(); 
    animal2->makeSound(); 

	std::cout << std::endl;
	std::cout << "\033[34m[type]\033[0m" << std::endl;
    std::cout << "Animal1 type: " << animal1->getType() << std::endl; // Output: Animal1 type: Cat
    std::cout << "Animal2 type: " << animal2->getType() << std::endl; // Output: Animal2 type: Dog

	std::cout << std::endl;
	std::cout << "\033[34m[destroying them]\033[0m" << std::endl;
    return 0;
}
