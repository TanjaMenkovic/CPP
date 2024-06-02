#include "replace.h"

int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		if (argv[1][0] == '\0' || argv[1][0] == '\n'
		|| argv[2][0] == '\0' || argv[2][0] == '\n'
		|| argv[3][0] == '\0' || argv[3][0] == '\n')
			error_msg(string("The values <filename>, <word_to_replace>, <word_to_replace_with> can't be empty"));
		
		replace(argv);
	}
	else
		error_msg(string("Wrong number of arguments!\nExpected the following input: <filename> <word_to_replace> <word_to_replace_with>"));

	return 0;
}
