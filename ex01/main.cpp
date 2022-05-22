/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 07:10:11 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/22 22:45:05 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "colors.h"

typedef	struct s_Data
{
	std::string	string;
	char		c;
	int			i;
	float		f;
	double		d;
}				Data;

uintptr_t	serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

int	main(void)
{
	Data	*	myData = new Data;
	uintptr_t	rawData;

	myData->string = "Hello World!";
	myData->c = 'H';
	myData->i = 42;
	myData->f = 08.15f;
	myData->d = 4711.0;
	std::cout << "string : " << myData->string << std::endl;
	std::cout << "char   : " << myData->c << std::endl;
	std::cout << "int    : " << myData->i << std::endl;
	std::cout << "float  : " << myData->f << std::endl;
	std::cout << "double : " << myData->d << std::endl;
	std::cout << COLOR_YELLOW << "Pointer to data structure before serialization: " << &myData << COLOR_DEFAULT << std::endl;
	
	rawData = serialize(myData);

	std::cout << "\n";

	myData = deserialize(rawData);
	
	std::cout << COLOR_YELLOW << "Pointer to data structure after deserialization: " << &myData << COLOR_DEFAULT << std::endl;
	std::cout << "string : " << myData->string << std::endl;
	std::cout << "char   : " << myData->c << std::endl;
	std::cout << "int    : " << myData->i << std::endl;
	std::cout << "float  : " << myData->f << std::endl;
	std::cout << "double : " << myData->d << std::endl;
	delete myData;
	return (0);
}

uintptr_t	serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
