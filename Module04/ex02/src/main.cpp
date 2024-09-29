/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:52:44 by jolopez-          #+#    #+#             */
/*   Updated: 2024/09/28 20:12:01 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include "Animal.hpp"


/*	Dog and Cat are derived classes from Animal, and therefore, their constructors
	first call the base class constructor (Animal) before executing the constructor
	of the derived class itself. Although Animal is now an abstract class (because
	makeSound() is a pure virtual method), the constructors of the derived classes 
	(Dog and Cat) still need to invoke the base class constructor Animal. This is
	part of the object construction process in C++. A direct instance of Animal is 
	not being created, but the constructor is invoked to initialize the Animal part
	that Dog and Cat inherit.

	Since Animal is an abstract class, it cannot be instantiated directly. This means
	that if you try to create a direct instance of Animal, you will get a compilation
	error.	*/
int main(void)
{
	Animal *doggy_1 = new Dog();
    Animal *catty_1 = new Cat();
	Animal *doggy_2(doggy_1);
	Animal *catty_2 = catty_1;

    doggy_1->makeSound();
    catty_1->makeSound();
	doggy_2->makeSound();
	catty_2->makeSound();

    delete doggy_1;
    delete catty_1;

	return 0;
}
