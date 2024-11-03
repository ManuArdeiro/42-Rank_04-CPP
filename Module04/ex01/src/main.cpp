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

	std::cout << "\033[1;36m\nDog	a;\033[0m" << std::endl;
	Dog		a;
	std::cout << "\033[1;36m\nDog	b(a);\033[0m" << std::endl;
	Dog b(a);
	std::cout << "\033[1;36m\nCat	a;\033[0m" << std::endl;
	Cat		c;
	std::cout << "\033[1;36m\nCat	b(a);\033[0m" << std::endl;
	Cat d(c);
	std::cout << "\033[1;36m\nDog	*e;\033[0m" << std::endl;
	Dog		*e = new Dog();
	std::cout << "\033[1;36m\nCat	*f;\033[0m" << std::endl;
	Cat		*f = new Cat();
	std::cout << "\033[1;36m\ndelete e;\033[0m" << std::endl;
	delete e;
	std::cout << "\033[1;36m\ndelete f;\033[0m" << std::endl;
	delete f;
	
	for (int i = 0; i < 4; i++)
	{
		if (i % 2 == 0)
		{
			std::cout << "\033[1;36m\npack[" << i << "] = new Dog()\033[0m" << std::endl;
			pack[i] = new Dog();
			pack[i]->makeSound();
		}
		else 
		{
			std::cout << "\033[1;36m\npack[" << i << "] = new Cat()\033[0m" << std::endl;
			pack[i] = new Cat();
			pack[i]->makeSound();			
		}
	}
	
	std::cout << "\033[1;36m\ndog_brain = pack[0]->getBrain()\033[0m" << std::endl;
	dog_brain = pack[0]->getBrain();
	std::cout << "\033[1;36m\ncat_brain = pack[1]->getBrain()\033[0m" << std::endl;
	cat_brain = pack[1]->getBrain();
	
	std::cout << "\033[1;36m\nideas[i]->ideas[i + 1];\033[0m" << std::endl;
	if (cat_brain != NULL && dog_brain != NULL)
	{
		cat_brain->ideas[0] = dog_brain->ideas[0] = "Idea 1";
		cat_brain->ideas[1] = dog_brain->ideas[1] = "Idea 2";
		cat_brain->ideas[2] = dog_brain->ideas[2] = "Idea 3";
		cat_brain->ideas[3] = dog_brain->ideas[3] = "Idea 4";
	}
	else
	{
		std::cerr << "Error: One of the brains is NULL." << std::endl;
	}

	std::cout << "\033[1;36m\npack[i]->getBrain()->ideas[i];\033[0m" << std::endl;
	std::cout << pack[0]->getBrain()->ideas[0] << std::endl;
	std::cout << pack[1]->getBrain()->ideas[1] << std::endl;
	std::cout << pack[2]->getBrain()->ideas[2] << std::endl;
	std::cout << pack[3]->getBrain()->ideas[3] << std::endl;
	
	std::cout << "\033[1;36m\n*(pack[3]) = *(pack[1]);\033[0m" << std::endl;
	*(pack[3]) = *(pack[1]);
	std::cout << "\033[1;36m\n*(pack[2]) = *(pack[0]);\033[0m" << std::endl;
	*(pack[2]) = *(pack[0]);
	
	std::cout << "\033[1;36m\npack[i]->getBrain()->ideas[i];\033[0m" << std::endl;
	std::cout << pack[0]->getType() << pack[0]->getBrain()->ideas[0] << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	std::cout << pack[1]->getBrain()->ideas[1] << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	std::cout << pack[2]->getBrain()->ideas[2] << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	std::cout << pack[3]->getBrain()->ideas[3] << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	std::cout << "\033[1;36m\ndelete pack[i];\033[0m" << std::endl;
	
	std::cout << "\033[1;36m\nNew scope!!\033[0m" << std::endl;
	{
		std::cout << "\033[1;36m\nDog	tmp;\033[0m" << std::endl;
		Dog		tmp;
		std::cout << "\033[1;36m\nBrain	tmp_brain\033[0m" << std::endl;
		Brain	*tmp_brain;
		std::cout << "\033[1;36m\ntmp_brain = tmp.getBrain();\033[0m" << std::endl;
		tmp_brain = tmp.getBrain();
		std::cout << "\033[1;36m\ntmp_brain->ideas[0] = Idea test\033[0m" << std::endl;
		tmp_brain->ideas[0] = "Idea test";
		std::cout << "\033[1;36m\na = tmp;\033[0m" << std::endl;
		a = tmp;
		std::cout << "tmp.getBrain()->ideas[0] = " << tmp.getBrain()->ideas[0] << std::endl;
		std::cout << "a.getBrain()->ideas[0] = " << a.getBrain()->ideas[0] << std::endl;
	}
	std::cout << "\033[1;36m\nEnd of scope!!\033[0m" << std::endl;

	std::cout << "a.getBrain()->ideas[0] = " << a.getBrain()->ideas[0] << std::endl;
	std::cout << "--------------------------\n" << std::endl;

	std::cout << "\033[1;36m\nNew scope!!\033[0m" << std::endl;
	{
		std::cout << "\033[1;36m\nDog	tmp_2 = a;\033[0m" << std::endl;
		Dog tmp_2 = a;
		std::cout << "\033[1;36m\nBrain	*tmp_brain_2 = tmp_2.getBrain();\033[0m" << std::endl;
		Brain *tmp_brain_2 = tmp_2.getBrain();
		std::cout << "\033[1;36mtmp_2.getBrain()->ideas[0] = " << tmp_2.getBrain()->ideas[0] << std::endl;
		std::cout << "\033[1;36mtmp_brain_2->ideas[0] = " << tmp_brain_2->ideas[0] << std::endl;
	}
	std::cout << "\033[1;36m\nEnd of scope!!\033[0m" << std::endl;
	std::cout << "a.getBrain()->ideas[0] = " << a.getBrain()->ideas[0] << std::endl;

	std::cout << "\033[1;36m\nDelete pack[i];\033[0m" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		delete pack[i];
	}

	std::cout << "\033[1;36m\nEnd of program!!\033[0m" << std::endl;

	return (0);
}
