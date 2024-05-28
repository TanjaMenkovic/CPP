/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:03:42 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/05/28 13:10:58 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

static void	print_upper_case(unsigned char **argv)
{
	int	i = 1;

	while (argv[i])
	{
		int	j = 0;

		while (argv[i][j])
		{
			std::cout << ((char)toupper(argv[i][j]));
			j++;
		}
		i++;
	}
	std::cout << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
		print_upper_case((unsigned char **)argv);
	return (0);
}
