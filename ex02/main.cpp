/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 07:11:57 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/22 23:24:27 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include "colors.h"

Base *	generate(void);
void	identify(Base * p);
void	identify(Base & p);

int	main(void)
{
	Base	*myBase;
	srand(time(NULL));

	for (int i = 0; i < 10; i++)
	{
		std::cout << "\n";
		std::cout << COLOR_YELLOW << "generate random Base object\n" << COLOR_DEFAULT;
		myBase = generate();
		std::cout << COLOR_YELLOW << "identify Base object with reference\n" << COLOR_DEFAULT;
		identify(myBase);
		std::cout << COLOR_YELLOW << "identify Base object with pointer\n" << COLOR_DEFAULT;
		identify(*myBase);
		std::cout << COLOR_YELLOW << "delete Base object\n" << COLOR_DEFAULT;
		delete myBase;
	}
	return (0);
}

Base *	generate(void)
{
	Base * output = NULL;
	int	random = -1;


	random = rand() % 3;
	std::cout << random << std::endl;
	switch (random)
	{
	case 0:
		output = new A();
		break;
	case 1:
		output = new B();
		break;
	case 2:
		output = new C();
		break;
	default:
		output = NULL;
		break;
	}
	return (output);
}

void	identify(Base * p)
{
	if (dynamic_cast<A *>(p) != NULL)
	{
		std::cout << COLOR_BLUE << "Base class <A> identified\n" << COLOR_DEFAULT;
		return ;
	}
	if (dynamic_cast<B *>(p) != NULL)
	{
		std::cout << COLOR_MAGENTA << "Base class <B> identified\n" << COLOR_DEFAULT;
		return ;
	}
	if (dynamic_cast<C *>(p) != NULL)
	{
		std::cout << COLOR_GREEN << "Base class <C> identified\n" << COLOR_DEFAULT;
		return ;
	}
}

void	identify(Base & p)
{
	try
	{
		(void) dynamic_cast<A &>(p);
		std::cout << COLOR_BLUE << "Base class <A> identified\n" << COLOR_DEFAULT;
		return ;
	}
	catch (std::exception & error)
	{
		std::cerr << COLOR_RED << error.what() << COLOR_DEFAULT << std::endl;
	}
	try
	{
		(void) dynamic_cast<B &>(p);
		std::cout << COLOR_MAGENTA << "Base class <B> identified\n" << COLOR_DEFAULT;
		return ;
	}
	catch (std::exception & error)
	{
		std::cerr << COLOR_RED << error.what() << COLOR_DEFAULT << std::endl;
	}
	try
	{
		(void) dynamic_cast<C &>(p);
		std::cout << COLOR_GREEN << "Base class <C> identified\n" << COLOR_DEFAULT;
		return ;
	}
	catch (std::exception & error)
	{
		std::cerr << COLOR_RED << error.what() << COLOR_DEFAULT << std::endl;
	}
}
