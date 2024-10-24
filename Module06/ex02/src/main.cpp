/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 01:38:05 by jolopez-          #+#    #+#             */
/*   Updated: 2024/10/18 17:48:26 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <typeinfo> // For typeid()
#include <cstdlib>  // For rand()
#include <ctime>    // For time()
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

/*	
	dynamic_cast is an operator in C++ used to perform safe conversions between
	types of polymorphic classes at runtime. It is used to convert a pointer or
	a reference from a base class to a derived class, ensuring that the conversion
	is valid. If the conversion is not possible, dynamic_cast returns a null
	pointer or throws an exception, depending on the type of conversion being
	attempted.
	
	Main characteristics of dynamic_cast:
	->	It only works with polymorphic classes: The base class must have at least
		one virtual method, usually the virtual destructor, for dynamic_cast to
		work. This is because dynamic_cast relies on the information from the
		virtual function tables (vtable) to determine the real type of the object
		at runtime.
	->	Runtime verification: Unlike static casts (static_cast), which are
		performed at compile time, dynamic_cast performs a runtime check to ensure
		that the conversion between types is safe.
	->	It is used for both upcasting and downcasting:
		-	Upcasting: Converting from a derived class to a base class. This is
			safe and can be done without dynamic_cast, but in some situations, you
			may choose to use it explicitly.
		-	Downcasting: Converting from a base class to a derived class. This can
			be dangerous if the object is not of the derived type to which you are
			casting, and this is where dynamic_cast is more useful, as it ensures
			the conversion is valid.
	->	Results of dynamic_cast:
		-	With pointers: If the conversion is successful, it returns a pointer to
			the desired type. If it is unsuccessful (i.e., the object is not of the
			derived class type you are trying to cast to), it returns a null
			pointer.
		-	With references: If the conversion is unsuccessful, it throws a
			std::bad_cast exception.	
	
	Advantages of dynamic casting (dynamic_cast) over static casting (static_cast):
	->	Runtime Verification.
	->	Safety in Downcasting: In the conversion from a base class to a derived class
		(downcasting), dynamic_cast is safer because it confirms whether the object
		is truly of the derived class before allowing the conversion. If it's not,
		the conversion safely fails.
		This is especially useful when you're unsure of the exact type of the object
		at compile time, as dynamic_cast ensures that the conversion is safe.
	
	Advantages of static casting (static_cast) over dynamic casting (dynamic_cast):
	->	Better Performance: static_cast is performed at compile time, making it faster
		than dynamic_cast, which performs runtime checks. This makes static_cast ideal
		in situations where you know the object type with certainty and the conversion
		is safe.
	->	Compatibility with Basic Types: static_cast can be used not only for polymorphic
		classes but also to perform conversions between basic types (like int to float
		or vice versa), or between unrelated pointers. It is more versatile in terms
		of the variety of conversions it allows.
	->	Simplicity: static_cast is simpler when runtime safety checks are unnecessary.
		If you know the exact type of the object and there is no risk of error,
		static_cast is the most straightforward and direct option.	*/

// Function to randomly generate an instance of A, B, or C
Base* generate()
{
    srand(static_cast<unsigned int>(time(0)));  // Seed for randomness
    int random = rand() % 3;  // Random number between 0 and 2

    if (random == 0)
	{
        std::cout << "Generated type: A" << std::endl;
        return new A();
    }
	else if (random == 1)
	{
        std::cout << "Generated type: B" << std::endl;
        return new B();
    }
	else
	{
        std::cout << "Generated type: C" << std::endl;
        return new C();
    }
}

// Function to identify the type by pointer
void identify(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Identified type: A" << std::endl;
	else if (dynamic_cast<B*>(p))
        std::cout << "Identified type: B" << std::endl;
	else if (dynamic_cast<C*>(p))
        std::cout << "Identified type: C" << std::endl;
	else
        std::cout << "Unknown type" << std::endl;
}

// Function to identify the type by reference
void identify(Base &p)
{
    try
	{
        (void)dynamic_cast<A&>(p);
        std::cout << "Identified type: A" << std::endl;
    }
	catch (const std::bad_cast&)
	{}

    try
	{
        (void)dynamic_cast<B&>(p);
        std::cout << "Identified type: B" << std::endl;
    }
	catch (const std::bad_cast&)
	{}

    try
	{
        (void)dynamic_cast<C&>(p);
        std::cout << "Identified type: C" << std::endl;
    }
	catch (const std::bad_cast&)
	{}
}

int main()
{
    // Generate a random instance of A, B, or C
    Base* basePtr = generate();

    // Identify the type using pointer
    identify(basePtr);

    // Identify the type using reference
    identify(*basePtr);

    delete basePtr;

    return 0;
}
