/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:07:19 by jolopez-          #+#    #+#             */
/*   Updated: 2024/10/18 19:11:54 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Template function that iterates over an array and applies a function to each element
template <typename T, typename F>
void iter(T *array, int length, F func)
{
    for (int i = 0; i < length; ++i)
	{
        func(array[i]);
    }
}
