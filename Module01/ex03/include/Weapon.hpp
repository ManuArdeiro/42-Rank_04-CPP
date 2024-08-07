/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 10:58:59 by jolopez-          #+#    #+#             */
/*   Updated: 2024/08/07 19:48:55 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	Header-protection
#pragma once

// includes
#include <string>
#include <iostream>

/*	If we declare a Weapon without a pointer and without a reference (i.e., by
	value), the Weapon will be copied. This means it can be less efficient,
	especially if the Weapon object is large, because it involves copying data.
	Besides that, changes to the original Weapon will not be reflected in the
	copy, and vice versa. This means that HumanA and HumanB would not see
	changes in the weapon type if the original Weapon changes, which might not
	be the desired behavior in this case.
	On HumanA and HumanB will declare a weapon by reference and by pointer.	*/
class Weapon
{
	public:
	std::string	getType(void);
	void		setType(std::string _type);
	
	Weapon(void);
	Weapon(const std::string _type);
	~Weapon();
	
	private:
	std::string	_type;
};