/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:52:44 by jolopez-          #+#    #+#             */
/*   Updated: 2024/09/28 20:04:42 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include "Animal.hpp"

int main(void)
{
	Animal	*pack[4];
	Brain	*cat_brain;
	Brain	*dog_brain;

	std::cout << "\033[1;34m\nDog	a;\033[0m" << std::endl;
	Dog		a;
	std::cout << "\033[1;34m\nDog	b(a);\033[0m" << std::endl;
	Dog b(a);
	std::cout << "\033[1;34m\nCat	a;\033[0m" << std::endl;
	Cat		c;
	std::cout << "\033[1;34m\nCat	b(a);\033[0m" << std::endl;
	Cat d(c);
	std::cout << "\033[1;34m\nDog	*e;\033[0m" << std::endl;
	Dog		*e = new Dog();
	std::cout << "\033[1;34m\nCat	*f;\033[0m" << std::endl;
	Cat		*f = new Cat();
	std::cout << "\033[1;34m\ndelete e;\033[0m" << std::endl;
	delete e;
	std::cout << "\033[1;34m\ndelete f;\033[0m" << std::endl;
	delete f;
	
	for (int i = 0; i < 4; i++)
	{
		if (i % 2 == 0)
		{
			std::cout << "\033[1;34m\npack[" << i << "] = new Dog()\033[0m" << std::endl;
			pack[i] = new Dog();
			pack[i]->makeSound();
		}
		else 
		{
			std::cout << "\033[1;34m\npack[" << i << "] = new Cat()\033[0m" << std::endl;
			pack[i] = new Cat();
			pack[i]->makeSound();			
		}
	}
	
	std::cout << "\033[1;34m\ndog_brain = pack[0]->get_brain()\033[0m" << std::endl;
	dog_brain = pack[0]->get_brain();
	std::cout << "\033[1;34m\ncat_brain = pack[0]->get_brain()\033[0m" << std::endl;
	cat_brain = pack[1]->get_brain();
	
	std::cout << "\033[1;34m\nideas[i]->ideas[i + 1];\033[0m" << std::endl;
	if (cat_brain != NULL && dog_brain != NULL) {
		cat_brain->ideas[0] = dog_brain->ideas[0] = "Idea 1";
		cat_brain->ideas[1] = dog_brain->ideas[1] = "Idea 2";
		cat_brain->ideas[2] = dog_brain->ideas[2] = "Idea 3";
		cat_brain->ideas[3] = dog_brain->ideas[3] = "Idea 4";
	} else {
		std::cerr << "Error: One of the brains is NULL." << std::endl;
	}
	
	std::cout << "\033[1;34m\npack[i]->get_brain()->ideas[i];\033[0m" << std::endl;
	std::cout << pack[0]->get_brain()->ideas[0] << std::endl;
	std::cout << pack[1]->get_brain()->ideas[1] << std::endl;
	std::cout << pack[2]->get_brain()->ideas[2] << std::endl;
	std::cout << pack[3]->get_brain()->ideas[3] << std::endl;
	
	std::cout << "\033[1;34m\npack[i]->get_brain()->ideas[i];\033[0m" << std::endl;
	std::cout << pack[0]->get_Type() << pack[0]->get_brain()->ideas[0] << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	std::cout << pack[1]->get_brain()->ideas[1] << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	std::cout << pack[2]->get_brain()->ideas[2] << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	std::cout << pack[3]->get_brain()->ideas[3] << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	
	std::cout << "\033[1;34m\n*(pack[3]) = *(pack[1]);\033[0m" << std::endl;
	*(pack[3]) = *(pack[1]);
	std::cout << "\033[1;34m\n*(pack[2]) = *(pack[0]);\033[0m" << std::endl;
	*(pack[2]) = *(pack[0]);
	
	std::cout << "\033[1;34m\npack[i]->get_brain()->ideas[i];\033[0m" << std::endl;
	std::cout << pack[0]->get_Type() << pack[0]->get_brain()->ideas[0] << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	std::cout << pack[1]->get_brain()->ideas[1] << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	std::cout << pack[2]->get_brain()->ideas[2] << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	std::cout << pack[3]->get_brain()->ideas[3] << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	std::cout << "\033[1;34m\ndelete pack[i];\033[0m" << std::endl;
	
	for (int i = 0; i < 4; i++)
	{
		delete pack[i];
	}

	return (0);
}
