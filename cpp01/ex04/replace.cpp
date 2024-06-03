/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 08:45:15 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/06/03 08:45:17 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.h"

void	error_msg(const string& input)
{
	if (!input.empty())
		cerr << input << endl;
	else
		cerr << "Unknown error!" << endl;
	exit (EXIT_FAILURE);
}

void	replace(char **argv)
{
	// opening files 
	string	input_file = argv[1];
	string	output_file = input_file + ".replace";

	ifstream	inFile;
	inFile.open(input_file.c_str());
	if (inFile.fail() || inFile.peek() == EOF)
		error_msg(string("File could not be opened for reading!"));

	ofstream	outFile;
	outFile.open(output_file.c_str());
	if (outFile.fail())
		error_msg(string("File could not be opened for writing!"));

	// replacing
	string	file_content;
	string	to_replace = (string)argv[2];
	string	replace_with = (string)argv[3];

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
