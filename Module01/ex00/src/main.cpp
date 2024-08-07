/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:39:13 by jolopez-          #+#    #+#             */
/*   Updated: 2024/08/01 12:56:59 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

    /*	Create a zombie on the heap:
		Objects created on the heap must be explicitly deallocated using delete
		to avoid memory leaks, but we have more control over the lifetime of
		these objects. The heap is much larger than the stack, allowing for the
		allocation of large objects or large amounts of data. It is generally
		slower than on the stack because it involves more complex operations,
		including potential fragmentation handling.
		
		Create a zombie on the stack:
		Objects created on the stack are automatically destroyed when going out
		of scope. This makes stack allocation simpler to manage, as there is no
		need for explicit deallocation. Besides it is very fast. But the stack
		has a limited size, which is determined at the start of the program.
		
		HeapZombie -> in this case we need the zombie to persist beyond the
		function call where it was created.	

		StackZombie -> is created on the stack and is automatically destroyed
		when the function randomChump returns.

		The difference to create a new Zombie in the heap or the stack is to
		use "new". "new" is what we need to assign memory dinamically, of
		course then we'll need to delete it manually.
	*/
int main() 
{
    Zombie* heapZombie = newZombie("HeapZombie");
    heapZombie->announce();
    delete heapZombie;
    randomChump("StackZombie");
	

    return 0;
}
