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
	//Animal test;

	std::cout << "\033[1;36m\nDog	doggy;\033[0m" << std::endl;
	Dog		doggy;
	std::cout << "\033[1;36m\nCat	catty;\033[0m" << std::endl;
	Cat		catty;

	std::cout << "\033[1;36m\ndoggy.getBrain()->ideas[0] = Doggy idea\033[0m" << std::endl;
	doggy.getBrain()->ideas[0] = "Doggy idea";
	std::cout << "\033[1;36m\ncatty.getBrain()->ideas[0] = Catty idea\033[0m" << std::endl;
	catty.getBrain()->ideas[0] = "Catty idea";

	std::cout << "\033[1;36m\nDog	doggyCopy(doggy);\033[0m" << std::endl;
	Dog		doggyCopy(doggy);
	std::cout << "\033[1;36m\nCat	cattyCopy(catty);\033[0m" << std::endl;
	Cat 	cattyCopy(catty);

	std::cout << "\033[1;36m\ndoggyCopy.getBrain()->ideas[0];\033[0m" << doggyCopy.getBrain()->ideas[0] << std::endl;
	std::cout << "\033[1;36m\ncattyCopy.getBrain()->ideas[0];\033[0m" << cattyCopy.getBrain()->ideas[0] << std::endl;

	std::cout << "\033[1;36m\nAnimal *doggy_1 = new Dog();\033[0m" << std::endl;
	Animal *doggy2 = new Dog();
	std::cout << "\033[1;36m\nAnimal *catty_1 = new Cat();\033[0m" << std::endl;
    Animal *catty2 = new Cat();

	std::cout << "\033[1;36m\ndoggy.makeSound();\033[0m" << std::endl;
	doggy.makeSound();
	std::cout << "\033[1;36m\ndoggyCopy.makeSound();\033[0m" << std::endl;
	doggyCopy.makeSound();
	std::cout << "\033[1;36m\ndoggy2->makeSound();\033[0m" << std::endl;
    doggy2->makeSound();
	std::cout << "\033[1;36m\ncatty.makeSound();\033[0m" << std::endl;
	catty.makeSound();
	std::cout << "\033[1;36m\ncattyCopy.makeSound();\033[0m" << std::endl;
	cattyCopy.makeSound();
	std::cout << "\033[1;36m\ncatty2->makeSound();\033[0m" << std::endl;
    catty2->makeSound();


    std::cout << "\033[1;36m\ndelete doggy_1;\033[0m" << std::endl;
	delete doggy2;
	std::cout << "\033[1;36m\ndelete catty_1;\033[0m" << std::endl;
    delete catty2;

	std::cout << "\033[1;36m\nEnd of program:\033[0m" << std::endl; 

	return 0;
}
