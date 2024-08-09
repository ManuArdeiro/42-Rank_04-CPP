/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 20:01:33 by jolopez-          #+#    #+#             */
/*   Updated: 2024/08/09 18:10:42 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>

std::string	replace_words(std::string line, const std::string word,
		const std::string replacer)
	{
		size_t	word_pos;
		
		word_pos = line.find(word);
		while (word_pos != std::string::npos)
		{
			line.erase(word_pos, word.length());
			line.insert(word_pos, replacer);
			word_pos = line.find(word);
		}
		return (line);
	}

/*	To open files:
	std::ios::in -> open to read.
	std::ios::out -> open to write.
	std::ios::app -> open to append (at the end of file).
	std::ios::trunc -> opens the file to write but the previopus content is deleted.
	std::ios::binary -> open in binary mode.
	
	peek() is a function to "spy" the next character to be readed.	
	
	.c_str() converts the std::string to const char*, what is expected by std::xfstream.	*/
int	read_file(std::string &filename, std::string word, std::string replacer)
{
	std::ifstream	inputFile(filename.c_str());
	std::ofstream	outputFile((filename + ".replace").c_str(), std::ios::out | std::ios::trunc);
	std::string		line;

	if (!inputFile.is_open())
	{
		std::cerr << "Input file can not be opened!!" << std::endl;
		return (EXIT_FAILURE);
	}
	if (!outputFile.is_open()) {
		std::cerr << "Output file can not be opened!!" << std::endl;
		return (EXIT_FAILURE);
	}
	while (std::getline(inputFile, line))
	{
		line = replace_words(line, word, replacer);
		outputFile << line;
		if (inputFile.peek() != EOF)
			outputFile << std::endl;
	}
	outputFile.close();
	return (EXIT_SUCCESS);
}
int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Incorrect number of arguments!!" << std::endl;
		return (EXIT_FAILURE);
	}
	std::string	filename = argv[1];
	std::string	word = argv[2];
	std::string	replacer = argv[3];
	
	if (read_file(filename, word, replacer))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}