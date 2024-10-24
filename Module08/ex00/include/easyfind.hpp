/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 18:10:31 by jolopez-          #+#    #+#             */
/*   Updated: 2024/10/20 19:55:10 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <algorithm>  // For std::find
#include <iterator>   // For std::distance
#include <exception>  // For std::exception

// Custom exception to throw when element is not found
class NotFoundException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return "Element not found in the container.";
		}
};

// Template function easyfind
template <typename T>
typename T::iterator easyfind(T &container, int value)
{
    // Use std::find to search for the value in the container
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
	{
        throw NotFoundException();  // Throw exception if value is not found
    }
    return it;  // Return the iterator if found
}

/*		typename T::iterator it = std::find(container.begin(), container.end(), value);
	->	typename T::iterator: This declares a variable it of type iterator for the
		generic container T. The use of typename is necessary in templates to indicate
		that T::iterator is a type because the C++ compiler cannot always deduce this
		automatically.
		T represents the generic container type (e.g., it could be a std::vector<int>,
		std::list<int>, etc.), and T::iterator is the iterator type associated with
		that container. This type varies for each container, so typename is required
		in a template.
	->	std::find(container.begin(), container.end(), value): std::find is a standard
		function from the <algorithm> library. It searches for a value in the range
		of elements defined by two iterators (begin() and end()).
			container.begin() returns an iterator pointing to the first element of
			the container container.
			container.end() returns an iterator pointing just past the last element
			of the container.
	->	The function std::find will traverse all the elements between container.begin()
		and container.end() and return an iterator pointing to the first occurrence of
		value. If value is not found, std::find returns the container's end() iterator,
		which indicates that the value was not found.	*/