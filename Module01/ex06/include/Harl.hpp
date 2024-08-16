/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 18:19:36 by jolopez-          #+#    #+#             */
/*   Updated: 2024/08/16 02:03:48 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	Header-protection
#pragma once

//	includes
#include <string>
#include <iostream>
#include <cstdio>
#include <cstdlib>

class Harl
{
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);

	public:
		Harl();
		~Harl();
		void	complain(std::string level);
};
