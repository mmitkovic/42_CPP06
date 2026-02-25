/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitkovi <mmitkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 17:18:58 by mmitkovi          #+#    #+#             */
/*   Updated: 2026/02/25 17:18:59 by mmitkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main(int ac, char*av[])
{
	if (ac != 2)
	{
		std::cout << "Wrong input!" << std::endl;
		return 1;
	}
	std::string input = av[1];
	ScalarConverter::convert(input);
	return 0;
}
