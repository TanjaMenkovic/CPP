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

int main()
{
    cout << "\033[38;5;213mConstructing\033[0m" << endl;
	const Animal	*meta = new Animal();
	cout << endl;
	cout << "\033[38;5;213mTesting\033[0m" << endl;

	cout << "Animal _type: " << meta->getType() << endl;
	meta->makeSound();
	cout << endl;

	cout << "\033[38;5;213mDeconstructing\033[0m" << endl;
	delete meta;
	cout << endl;

	cout << "-------------------------------------------------------" << endl;

	cout << endl;
	cout << "\033[34mConstructing\033[0m" << endl;
	const Animal	*catto = new Cat();
	cout << endl;

	cout << "\033[34mTesting\033[0m" << endl;
	cout << "Cat _type: " << catto->getType() << endl;
	catto->makeSound();
	cout << endl;

	cout << "\033[34mDeconstructing\033[0m" << endl;
	delete catto;
	cout << endl;

	cout << "-------------------------------------------------------" << endl;

	cout << endl;
	cout << "\033[34mConstructing\033[0m" << endl;
	const Animal	*doggo = new Dog();
	cout << endl;
	cout << "\033[34mTesting\033[0m" << endl;
	cout << "Dog _type: " << doggo->getType() << endl;
	doggo->makeSound();
	cout << endl;
	cout << "\033[34mDeconstructing\033[0m" << endl;
	delete doggo;
	cout << endl;

	cout << "-------------------------------------------------------" << endl;

	cout << endl;
	cout << "\033[38;5;213mConstructing\033[0m" << endl;
	const WrongAnimal	*wrong_meta = new WrongAnimal();
	cout << endl;

	cout << "\033[38;5;213mTesting\033[0m" << endl;
	cout << "Animal _type: " << wrong_meta->getType() << endl;
	wrong_meta->makeSound();
	cout << endl;

	cout << "\033[38;5;213mDeconstructing\033[0m" << endl;
	delete wrong_meta;
	cout << endl;

	cout << "-------------------------------------------------------" << endl;

	cout << "\033[34mConstructing\033[0m" << endl;
	const WrongAnimal	*wrong_catto = new WrongCat();
	cout << endl;

	cout << "\033[34mTesting\033[0m" << endl;
	cout << "WrongCat _type: " << wrong_catto->getType() << endl;
	wrong_catto->makeSound();
	cout << endl;

	cout << "\033[34mDeconstructing\033[0m" << endl;
	delete wrong_catto;
	cout << endl;

    return 0;
}
