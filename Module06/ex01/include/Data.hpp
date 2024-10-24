/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 21:07:38 by jolopez-          #+#    #+#             */
/*   Updated: 2024/10/17 21:08:36 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

// Simple Data structure with some example members
struct Data
{
    int			number;
    std::string	text;

    // Canonical form
    Data();                              // Default constructor
    Data(const Data &other);             // Copy constructor
    Data &operator=(const Data &other);  // Assignment operator
    ~Data();                             // Destructor
};
