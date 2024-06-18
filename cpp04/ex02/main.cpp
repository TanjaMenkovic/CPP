/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:11:37 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/06/17 17:11:40 by tmenkovi         ###   ########.fr       */
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
    cout << endl;
	cout << "\033[34m[creating them]\033[0m" << endl;
	Cat cat;
    Dog dog;

    Animal* animal1 = &cat;
    Animal* animal2 = &dog;
	
	cout << endl;
	cout << "\033[34m[sound]\033[0m" << endl;
    animal1->makeSound(); 
    animal2->makeSound(); 

	cout << endl;
	cout << "\033[34m[type]\033[0m" << endl;
    cout << "Animal1 type: " << animal1->getType() << endl; // Output: Animal1 type: Cat
    cout << "Animal2 type: " << animal2->getType() << endl; // Output: Animal2 type: Dog

	cout << endl;
	cout << "\033[34m[destroying them]\033[0m" << endl;
    return 0;
}
