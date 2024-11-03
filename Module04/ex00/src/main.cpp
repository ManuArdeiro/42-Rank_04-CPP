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
	std::cout << "\033[36m\nconst Animal* meta = new Animal();\033[0m" << std::endl;
	const Animal* meta = new Animal();
	std::cout << "\033[36m\nconst Animal* j = new Dog();\033[0m" << std::endl;
	const Animal* j = new Dog();
	std::cout << "\033[36m\nconst Animal* i = new Cat();\033[0m" << std::endl;
	const Animal* i = new Cat();
	
	std::cout << "\033[35m\n---------------------------------\033[0m" << std::endl;
	std::cout << "\033[36m\nmeta->getType() = " << meta->getType() << "\033[0m" << std::endl;
	std::cout << "\033[36m\nj->getType() = " << j->getType() << "\033[0m" << std::endl;
	std::cout << "\033[36m\ni->getType() = " << i->getType() << "\033[0m" << std::endl;
	std::cout << "\033[35m\n---------------------------------\033[0m" << std::endl;
	std::cout << "\033[36m\ni->makeSound();\033[0m" << std::endl;
	i->makeSound(); //will output the cat sound!
	std::cout << "\033[36m\nj->makeSound();\033[0m" << std::endl;
	j->makeSound();
	std::cout << "\033[36m\nmeta->makeSound();\033[0m" << std::endl;
	meta->makeSound();
	std::cout << "\033[35m\n---------------------------------\033[0m" << std::endl;
	std::cout << "\033[36m\ndelete meta;\033[0m" << std::endl;
	delete meta;
	std::cout << "\033[36m\ndelete j;\033[0m" << std::endl;
	delete j;
	std::cout << "\033[36m\ndelete i;\033[0m" << std::endl;
	delete i;

	std::cout << "\033[36m\nconst WrongAnimal* a = new WrongCat();\033[0m" << std::endl;
	const WrongAnimal* a = new WrongCat();
	std::cout << "\033[36m\nconst WrongCat* b = new WrongCat();\033[0m" << std::endl;
	const WrongCat* b = new WrongCat();

	std::cout << "\033[35m\n---------------------------------\033[0m" << std::endl;
	std::cout << "\033[36m\na->getType() = " << a->getType() << "\033[0m" << std::endl;
	std::cout << "\033[36m\nb->getType() = " << b->getType() << "\033[0m" << std::endl;
	std::cout << "\033[35m\n---------------------------------\033[0m" << std::endl;
	std::cout << "\033[36m\na->makeSound();\033[0m" << std::endl;
	a->makeSound();
	std::cout << "\033[36m\nb->makeSound();\033[0m" << std::endl;
	b->makeSound(); //will output the wrong cat sound!
	std::cout << "\033[35m\n---------------------------------\033[0m" << std::endl;
	std::cout << "\033[36m\ndelete a;\033[0m" << std::endl;
	delete a;
	std::cout << "\033[36m\ndelete b;\033[0m" << std::endl;
	delete b;
	return 0;
}