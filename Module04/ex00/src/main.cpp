/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 10:18:21 by jolopez-          #+#    #+#             */
/*   Updated: 2024/09/24 18:42:52 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

/*		const Dog* j = new Dog();
	Here, you are creating an object of type Dog (new Dog()) and storing its
	address in a pointer of type const Dog*. The pointer j is specific to Dog,
	which means it can only point to Dog objects or classes that derive from Dog
	(if any exist). There is no polymorphism in this case because you are working
	directly with the Dog type.
	
		const Animal* j = new Dog();
	Here, you are creating an object of type Dog (new Dog()) and storing its
	address in a pointer of type const Animal*. This means that the pointer j
	is of type Animal*, which implies it can point to any object derived from
	Animal (such as Dog in this case).

	Polymorphism:
	Pointing to an object of a derived class, like Cat, using a pointer or reference
	to the base class (Animal) makes sense in the context of polymorphism. This
	allows you to uniformly treat all objects derived from the same base class,
	like Animal, regardless of their specific type (for example, using a for loop).
*/
int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;

	const WrongAnimal* a= new WrongCat();
	const WrongCat* b = new WrongCat();

	std::cout << b->getType() << " " << std::endl;
	b->makeSound(); //will output the wrong cat sound!
	a->makeSound();
	delete a;
	delete b;
	return 0;
}