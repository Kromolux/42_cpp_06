/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 07:12:10 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/22 16:22:25 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Converter.hpp"

int	main(int const argc, char const **argv)
{
	if (argc != 2)
	{
		std::cout << "Error\nProgram needs one argument to convert!\nchar, int, float or double in decimal notation.\n";
		return (-1);
	}
	Converter	userInput(argv[1]);
	userInput.convert();
	return (0);
}
