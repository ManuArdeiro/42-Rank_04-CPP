/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:09:00 by jolopez-          #+#    #+#             */
/*   Updated: 2024/10/29 19:09:17 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdexcept>

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <sys/time.h>
#include <cstring>
#include <limits>
#include "PmergeMe.hpp"
#include <cstdio>

/*	Supongamos que tenemos el siguiente contenedor de enteros:
	
	std::vector<int> array = {5, 2, 9, 1, 5, 6};

	Paso 1: Verificar el tamaño del contenedor

		El tamaño del contenedor es 6, por lo que continuamos con el siguiente paso.

	Paso 2: Verificar si el número de elementos es impar

	Paso 3: Agrupar los elementos en pares
	
		Agrupamos los elementos en pares y comparamos cada par:
		(5, 2) -> (2, 5)
		(9, 1) -> (1, 9)
		(5, 6) -> (5, 6)

		El contenedor pairs será: [(2, 5), (1, 9), (5, 6)]

	Paso 4: Imprimir los pares si VERBOSE está habilitado

		Pairs: [2, 5], [1, 9], [5, 6],

	Paso 5: Ordenar recursivamente los pares
	
		Llamamos a sort_pairs para ordenar los pares:
		sort_pairs divide los pares en dos mitades y las ordena recursivamente:
		Primera mitad: [(2, 5)]
		Segunda mitad: [(1, 9), (5, 6)]
		Ordenamos la segunda mitad:
		Dividimos en dos mitades: [(1, 9)] y [(5, 6)]
		Ambas mitades ya están ordenadas, así que las combinamos: [(1, 9), (5, 6)]
		Combinamos las dos mitades ordenadas: [(1, 9), (2, 5), (5, 6)]

	Paso 6: Imprimir los pares ordenados si VERBOSE está habilitado

		Pair sorted: [1, 9], [2, 5], [5, 6],

	Paso 7: Crear la secuencia ordenada S

		Creamos el contenedor sorted y añadimos el primer elemento de cada par ordenado: 
		sorted = [1, 2, 5]
	
	Paso 8: Imprimir los elementos ordenados si VERBOSE está habilitado
	
		Sorted: [1, 2, 5]

	Paso 9: Insertar los elementos restantes utilizando búsqueda binaria

		Insertamos los elementos restantes de los pares en sorted utilizando búsqueda binaria:
		Insertamos 9: sorted = [1, 2, 5, 9]
		Insertamos 5: sorted = [1, 2, 5, 5, 9]
		Insertamos 6: sorted = [1, 2, 5, 5, 6, 9]
	
	Paso 10: Retornar el contenedor ordenado
*/

/*
	- static: La función get_timestamp se declara como static, lo que significa que su alcance está limitado al archivo en el que se define. No puede ser llamada desde otros archivos.
	- timestamp_t get_timestamp(void): La función devuelve un valor de tipo timestamp_t y no toma argumentos.
	- struct timeval now;: Se declara una variable now de tipo struct timeval. Esta estructura se utiliza para almacenar el tiempo en segundos y microsegundos.
	- gettimeofday(&now, NULL);: La función gettimeofday llena la estructura now con el tiempo actual. El primer argumento es un puntero a la estructura timeval y el segundo argumento es un puntero a una estructura timezone, que en este caso es NULL porque no se utiliza.
	- return (now.tv_usec + (timestamp_t)now.tv_sec * 1000000);: La función devuelve la marca de tiempo en microsegundos. Se convierte el tiempo en segundos (now.tv_sec) a microsegundos multiplicándolo por 1,000,000 y se suma el valor de microsegundos (now.tv_usec).
*/

typedef unsigned long long timestamp_t;

static	timestamp_t get_timestamp(void)
{
	struct timeval now;
	gettimeofday(&now, NULL);
	return ((timestamp_t)now.tv_sec * 1000000 + now.tv_usec);
}

int main(int argc, char **argv)
{
	std::vector<int>    originVector;
	std::deque<int>     originDeque; // deque -> utiles para insertar/eliminar elementos al principio y final.

    if (argc < 2)
    {
        std::cout << "Usage: ./PmergeMe <sequence_of_positive_integers>" << std::endl;
        return 1;
    }

    for (int i = 1; i < argc; ++i)
    {
        if (std::string(argv[i]).find_first_not_of("0123456789") != std::string::npos)
        {
            std::cerr << "Error: " << argv[i] << " is not a positive integer." << std::endl;
        }
        int value = std::atoi(argv[i]);

        if (ft_contains(this->_vector, value))
        {
            std::cerr << "Error: " << argv[i] << " is duplicated." << std::endl;
        }
        
        originVector.push_back(value);
        originDeque.push_back(value);
    }
	
	PmergeMe    vector_merge;
    PmergeMe    deque_merge;

    //  Cálculo de ordenación de los elementos en el vector:
    timestamp_t startVector = get_timestamp();
    std::vector<int> orderedVector = vector_merge.sort(originVector);
	timestamp_t endVector = get_timestamp();

	std::cout << "Ordered values: " << std::endl;
	for (size_t i = 0; i < orderedVector.size(); ++i)
    {
		std::cout << orderedVector[i] << std::endl;
    }
	std::cout << "Time to process " << originVector.size() << " elements with vector: " << std::endl;
    std::cout << endVector - startVector << " microseconds." << std::endl;
    
    if (orderedVector.size() != originVector.size())
    {
        std::cerr << "Error: el número de elementos no coincide tras la ordenación." << std::endl;
        return 1;
    }
    bool isOrdered = true;
    for (size_t i = 1; i < orderedVector.size(); ++i)
    {
        if (orderedVector[i - 1] > orderedVector[i])
        {
            isOrdered = false;
            break;
        }
    }
    if (!isOrdered)
    {
        std::cerr << "Error: los elementos no están correctamente ordenados." << std::endl;
        return 1;
    }
    std::cout << "✅ Comprobaciones superadas: número de elementos y orden correctos." << std::endl;

	timestamp_t startDeque = get_timestamp();
    std::deque<int> orderedDeque = deque_merge.sort(originDeque);
    timestamp_t endDeque = get_timestamp();

    std::cout << "Ordered values: " << std::endl;
	for (size_t i = 0; i < orderedDeque.size(); ++i)
    {
        std::cout << orderedDeque[i] << std::endl;
    }
	std::cout << "Time to process " << originDeque.size() << " elements with deque: " << std::endl;
    std::cout << endDeque - startDeque << " microseconds." << std::endl;

    if (orderedDeque.size() != originDeque.size())
    {
        std::cerr << "Error: el número de elementos no coincide tras la ordenación." << std::endl;
        return 1;
    }
    bool isOrdered = true;
    for (size_t i = 1; i < orderedDeque.size(); ++i)
    {
        if (orderedDeque[i - 1] > orderedDeque[i])
        {
            isOrdered = false;
            break;
        }
    }
    if (!isOrdered)
    {
        std::cerr << "Error: los elementos no están correctamente ordenados." << std::endl;
        return 1;
    }
    std::cout << "✅ Comprobaciones superadas: número de elementos y orden correctos." << std::endl;

    if ((endVector - startVector) < (endDeque - startDeque))
    {
        std::cout << "🏆 Winner: Vector is faster by " 
                  << (endDeque - startDeque) - (endVector - startVector) 
                  << " microseconds." << std::endl;
    }
    else if ((endVector - startVector) > (endDeque - startDeque))
    {
        std::cout << "🏆 Winner: Deque is faster by " 
                  << (endVector - startVector) - (endDeque - startDeque) 
                  << " microseconds." << std::endl;
    }
    else
    {
        std::cout << "🤝 It's a tie! Both took the same time." << std::endl;
    }
}