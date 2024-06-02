#ifndef REPLACE_H
# define REPLACE_H

# include <iostream>
# include <string>
# include <fstream> // file I/O operations

using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::string;
using std::ifstream; // input file stream, object for reading from file
using std::ofstream; // output file stream, object for writing to a file
using std::cerr;

void	error_msg(const string& input);
void	replace(char **argv);

#endif
