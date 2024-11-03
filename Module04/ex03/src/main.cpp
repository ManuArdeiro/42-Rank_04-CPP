/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 21:27:10 by jolopez-          #+#    #+#             */
/*   Updated: 2024/09/29 17:28:53 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "AMateria.hpp"

int	main(void)
{
	std::cout << "\033[1;36m\nMateriaSource *src = new MateriaSource();\033[0m" << std::endl;
	IMateriaSource *src = new MateriaSource();
	std::cout << "\033[1;36msrc->learnMateria(new Ice());\033[0m" << std::endl;
	src->learnMateria(new Ice());
	std::cout << "\033[1;36msrc->learnMateria(new Cure());\033[0m" << std::endl;
	src->learnMateria(new Cure());
	std::cout << "\033[1;36mICharacter *me = new Character(\"me\");\033[0m" << std::endl;
	ICharacter *me = new Character("me");
	std::cout << "\033[1;36mICharacter *bob = new Character(\"bob\");\033[0m" << std::endl;
	ICharacter *bob = new Character("bob");
	std::cout << "\033[1;36mAMateria *tmp;\033[0m" << std::endl;
	AMateria *tmp;
	
	std::cout << "\033[1;36mme->equip(src->createMateria(\"ice\"));\033[0m" << std::endl;
	tmp = src->createMateria("ice");
	std::cout << "\033[1;36mme->equip(tmp);\033[0m" << std::endl;
	me->equip(tmp);
	std::cout << "\033[1;36mme->equip(src->createMateria(\"cure\"));\033[0m" << std::endl;
	tmp = src->createMateria("cure");
	std::cout << "\033[1;36mme->equip(tmp);\033[0m" << std::endl;
	me->equip(tmp);
	std::cout << "\033[1;36mme->use(0, *bob);\033[0m" << std::endl;
	me->use(0, *bob);
	std::cout << "\033[1;36mme->use(1, *bob);\033[0m" << std::endl;
	me->use(1, *bob);
	
	std::cout << "\033[1;36mdelete bob;\033[0m" << std::endl;
	delete bob;
	std::cout << "\033[1;36mdelete me;\033[0m" << std::endl;
	delete me;
	std::cout << "\033[1;36mdelete src;\033[0m" << std::endl;
	delete src;
	
	return 0;
}
