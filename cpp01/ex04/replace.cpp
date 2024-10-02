/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 08:45:15 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/10/02 11:11:15 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.h"

void	error_msg(const std::string& input)
{
	if (!input.empty())
		std::cerr << input << std::endl;
	else
		std::cerr << "Unknown error!" << std::endl;
	exit(EXIT_FAILURE);
}

void	replace(char **argv)
{
	// opening files 
	std::string	input_file = argv[1];
	std::string	output_file = input_file + ".replace";

	std::ifstream	inFile;
	inFile.open(input_file.c_str());
	if (inFile.fail() || inFile.peek() == EOF)
		error_msg(std::string("File could not be opened for reading!"));

	std::ofstream	outFile;
	outFile.open(output_file.c_str());
	if (outFile.fail())
		error_msg(std::string("File could not be opened for writing!"));

	// replacing
	std::string	file_content;
	std::string	to_replace = (std::string)argv[2];
	std::string	replace_with = (std::string)argv[3];

	size_t	to_replace_len = to_replace.length();

	getline(inFile, file_content, '\0');

	int idx;
	while ((idx = file_content.find(to_replace)) != -1)
	{
		file_content.erase(idx, to_replace_len);
		file_content.insert(idx, replace_with);
	}
	outFile << file_content;

	inFile.close();
	outFile.close();
}
