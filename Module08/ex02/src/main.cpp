/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:49:20 by jolopez-          #+#    #+#             */
/*   Updated: 2024/10/23 18:55:27 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
    // Test 1: Basic stack functionality with integers
    std::cout << "Test 1: Basic stack functionality with integers" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "Top element: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Stack size after pop: " << mstack.size() << std::endl; 
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    // Test 2: Iterating through the stack using iterators
    std::cout << "\nTest 2: Iterating through the stack" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    std::cout << "Stack elements: ";
    while (it != ite)
	{
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;

    // Test 3: Copy constructor
    std::cout << "\nTest 3: Copy constructor test" << std::endl;
    MutantStack<int> mstackCopy(mstack);
    std::cout << "Top element of copied stack: " << mstackCopy.top() << std::endl;
    mstackCopy.pop();
    std::cout << "Top element of copied stack after pop: " << mstackCopy.top() << std::endl;

    // Test 4: Assignment operator
    std::cout << "\nTest 4: Assignment operator test" << std::endl;
    MutantStack<int> mstackAssign;
    mstackAssign = mstack;
    std::cout << "Top element of assigned stack: " << mstackAssign.top() << std::endl;
    mstackAssign.pop();
    std::cout << "Top element of assigned stack after pop: " << mstackAssign.top() << std::endl;

    // Test 5: Reverse iterators
    std::cout << "\nTest 5: Iterating in reverse order" << std::endl;
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    std::cout << "Stack elements in reverse: ";
    while (rit != rite)
	{
        std::cout << *rit << " ";
        ++rit;
    }
    std::cout << std::endl;

    // Test 6: Const iterators
    std::cout << "\nTest 6: Using const iterators" << std::endl;
    const MutantStack<int>& constMstack = mstack;
    MutantStack<int>::const_iterator constIt = constMstack.begin();
    MutantStack<int>::const_iterator constIte = constMstack.end();
    std::cout << "Const stack elements: ";
    while (constIt != constIte)
	{
        std::cout << *constIt << " ";
        ++constIt;
    }
    std::cout << std::endl;

    // Test 7: Large data handling
    std::cout << "\nTest 7: Handling large amounts of data" << std::endl;
    MutantStack<int> largeStack;
    for (int i = 0; i < 10000; ++i)
	{
        largeStack.push(i);
    }
    std::cout << "Top element of large stack: " << largeStack.top() << std::endl;
    std::cout << "Size of large stack: " << largeStack.size() << std::endl;

    // Test 8: Using a different container type (comparison with std::list)
    std::cout << "\nTest 8: Comparison with std::list" << std::endl;
    std::list<int> testList;
    testList.push_back(5);
    testList.push_back(17);
    testList.push_back(3);
    testList.push_back(5);
    testList.push_back(737);
    testList.push_back(0);
    std::cout << "List elements: ";
    for (std::list<int>::iterator lit = testList.begin(); lit != testList.end(); ++lit)
	{
        std::cout << *lit << " ";
    }
    std::cout << std::endl;

    return 0;
}
