/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 19:59:32 by jolopez-          #+#    #+#             */
/*   Updated: 2024/10/23 18:31:23 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

/*	In C++, containers are data structures provided by the Standard Template
	Library (STL) that store collections of objects. Containers allow you to
	manage and access your data efficiently and provide built-in operations like
	insertion, deletion, searching, and sorting. Containers come in various types,
	each optimized for different use cases, depending on how you want to store
	and retrieve the data.

	Types of Containers:
	
	->	SEQUENCE CONTAINERS: Store elements in a linear sequence. The elements are
		stored in the order in which they are inserted.
		->	Vector (std::vector): A dynamic array that can change size automatically.
			It allows fast random access, but insertion or deletion of elements
			(except at the end) can be costly.
			Example: std::vector<int> v = {1, 2, 3};
		->	List (std::list): A doubly linked list. It allows fast insertion and
			deletion at any point but slower random access (no direct indexing).
			Example: std::list<int> l = {1, 2, 3};
		->	Deque (std::deque): Double-ended queue that allows fast insertions and
			deletions at both ends, while also supporting efficient random access.
			Example: std::deque<int> d = {1, 2, 3};
	->	ASSOCIATIVE CONTAINERS: Store elements in key-value pairs and automatically
		sort them based on the keys. These containers offer fast searching,
		insertion, and deletion.
			->	Map (std::map): A sorted associative container that stores key-value
			pairs, where each key is unique.
			Example: std::map<int, std::string> m; m[1] = "one";
		->	Set (std::set): A collection of unique elements stored in a specific
			order. Useful for eliminating duplicates.
			Example: std::set<int> s = {1, 2, 3};
		->	Multimap (std::multimap): Similar to map, but allows multiple values for
			the same key.
			Example: std::multimap<int, std::string> mm;
		->	Multiset (std::multiset): Similar to set, but allows duplicate values.
			Example: std::multiset<int> ms = {1, 1, 2, 3};
	->	UNORDERED ASSOCIATIVE CONTAINERS: Like associative containers, but the
		elements are not sorted. They use hashing for fast access.
		->	Unordered Map (std::unordered_map): A hash-based associative container
			for key-value pairs, where the keys are not sorted but hashed for quick
			lookup.
			Example: std::unordered_map<int, std::string> umap;
		->	Unordered Set (std::unordered_set): A hash-based collection of unique
			elements, without any order.
			Example: std::unordered_set<int> uset = {1, 2, 3};
	->	CONTAINER ADAPTERS: These containers modify other containers to provide
		specific interfaces. They are typically wrappers around other containers.
		->	Stack (std::stack): Provides a Last-In-First-Out (LIFO) access pattern.
			Usually implemented using a deque or a vector.
			Example: std::stack<int> s;
		->	Queue (std::queue): Provides a First-In-First-Out (FIFO) access pattern.
			Implemented with a deque or list.
			Example: std::queue<int> q;
		->	Priority Queue (std::priority_queue): A queue where elements are ordered
			based on priority (typically the largest element comes first).
			Example: std::priority_queue<int> pq;

Key Properties of Containers:

	->	Type Safety: STL containers are template-based, which means they can
		hold elements of any type, offering type safety at compile time.
		Example: std::vector<int> holds integers, and trying to store another
		type would cause a compile-time error.
	->	Iterators: All containers provide iterators, which are objects that
		allow you to traverse the elements in the container. Iterators abstract
		away the underlying structure and allow you to interact with containers
		in a consistent way.
		Example: std::vector<int>::iterator it = v.begin();
	->	Algorithms: Containers can work seamlessly with STL algorithms like
		std::sort, std::find, etc., which allows you to manipulate and access
		elements in efficient ways.

When to Use Each Container:

	->	Use a vector when you need fast access by index and don't need to insert
		or delete elements frequently (except at the end).
	->	Use a list when you need frequent insertions and deletions from both
		ends or the middle but don't require random access.
	->	Use a map or unordered_map when you need to associate keys with values
		and search for elements efficiently.
	->	Use a set or unordered_set when you want to store unique elements and
		need fast searching capabilities.

Conclusion:

C++ containers offer flexible and efficient ways to store and manipulate data.
Choosing the right container depends on the specific requirements of your
application, such as how you need to access elements, how you want to store
them, and what kind of performance you need.
*/
class Span
{
	private:
		std::vector<int>	_numbers;	// Stores the integers
		unsigned int 		_maxSize;	// Maximum number of elements (N)

	public:
		// Constructors
		Span(unsigned int N);
		Span(const Span &other);
		Span &operator=(const Span &other);

		// Destructor
		~Span();

		// Methods
		void addNumber(int number);
		int shortestSpan() const;
		int longestSpan() const;
		unsigned int size() const;
		
		template <typename Iterator>
		void addNumbers(Iterator begin, Iterator end);
};

// Template function definition must be in the header file
template <typename Iterator>
void Span::addNumbers(Iterator begin, Iterator end)
{
    if (std::distance(begin, end) + _numbers.size() > _maxSize)
        throw std::overflow_error("Adding this range will exceed the maximum size of the Span.");
    _numbers.insert(_numbers.end(), begin, end);
}
/*	Last line is adding the elements from begin to end at the position 
	indicated by _numbers.end(), meaning it inserts them right at the
	end of the vector _numbers.	*/
	