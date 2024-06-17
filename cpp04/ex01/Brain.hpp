/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:09:53 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/06/17 18:09:56 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;

class Brain
{
	private:
		string _ideas[100];

	public:
		Brain();
		Brain(const Brain &copy);
		virtual ~Brain();
		Brain &operator=(const Brain &src);

		const string getIdea(size_t i)const;
		const string *getIdeaAddress(size_t i)const;

		void setIdea(size_t i, string idea);
};
