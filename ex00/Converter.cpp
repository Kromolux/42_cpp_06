/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 10:27:56 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/22 17:27:27 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

Converter::Converter(char const * userInput) : _UserInput(static_cast<std::string>(userInput))
{
	if (DEBUG)
		std::cout << COLOR_MAGENTA << "[Converter] default constructor called " << std::endl << COLOR_DEFAULT;
	initValues();
}

Converter::Converter(Converter const & obj) : _UserInput(obj._UserInput)
{
	if (DEBUG)
		std::cout << COLOR_MAGENTA << "[Converter] copy constructor called " << std::endl << COLOR_DEFAULT;
	*this = obj;
}

Converter const & Converter::operator=(Converter const & obj)
{
	if (DEBUG)
		std::cout << COLOR_MAGENTA << "[Converter] assginment constructor called " << std::endl << COLOR_DEFAULT;
	(void) obj;
	return (*this);
}

Converter::~Converter(void)
{
	if (DEBUG)
		std::cout << COLOR_MAGENTA << "[Converter] destructor called " << std::endl << COLOR_DEFAULT;
}

void	Converter::initValues(void)
{
	this->_type = -2;
	this->_specialType = false;
	this->_myChar = ' ';
	this->_myInt = 0;
	this->_myFloat = 0.0f;
	this->_myDouble = 0.0;
}

void	Converter::convert(void)
{
	this->_type = getDataType();
	std::cout << "type is: ";
	switch (this->_type)
	{
	case TYPE_CHAR:
		std::cout << "char\n";
		break;
	case TYPE_INT:
		std::cout << "int\n";
		break;
	case TYPE_FLOAT:
		std::cout << "float\n";
		break;
	case TYPE_DOUBLE:
		std::cout << "double\n";
		break;
	case TYPE_INVALID:
		std::cout << "invalid\n";
		break;
	default:
		std::cout << "ERROR!\n";
		break;
	}
	if (this->_specialType)
		std::cout << " special type\n";
}

int	Converter::getDataType(void)
{
	if (_UserInput.length() == 0)
		return (TYPE_INVALID);
	if (_UserInput.length() == 1)
	{
		if (isalpha(_UserInput[0]) == true)
			return (TYPE_CHAR);
		if (isdigit(_UserInput[0]) == true)
			return (TYPE_INT);
		return (TYPE_INVALID);
	}
	if (isInt() == true)
		return (TYPE_INT);
	if (isFloat() == true)
		return (TYPE_FLOAT);
	if (isDouble() == true)
		return (TYPE_DOUBLE);
	return (TYPE_INVALID);
}

bool	Converter::isNumber(void)
{
	if (_UserInput[0] != '-' && _UserInput[0] != '+' && !isdigit(_UserInput[0]))
		return (false);
	bool	point = false;
	for (unsigned long i = 1; _UserInput[i]; i++)
	{
		if (_UserInput[i] == '.')
		{
			if(point == false)
				point = true;
			else
				return (false);
		}
		else if (isdigit(_UserInput[i]) == false && _UserInput[i] == 'f' && (_UserInput.length() - 1) > i)
			return (false);
	}
	return (true);
}

bool	Converter::isInt(void)
{
	if (_UserInput[0] != '-' && _UserInput[0] != '+' && !isdigit(_UserInput[0]))
		return (false);
	for (unsigned long i = 1; _UserInput[i]; i++)
	{
		if (isdigit(_UserInput[i]) == false)
			return (false);
	}
	return (true);
}

bool	Converter::isFloat(void)
{
	std::string	const specialType[3] = {"-inff", "+inff", "nanf"};

	for (unsigned long i = 0; i < 3; i++)
	{
		if (_UserInput == specialType[i])
		{
			this->_specialType = true;
			return (true);
		}
	}
	if (isNumber() && _UserInput[_UserInput.length() - 1] == 'f')
		return (true);
	return (false);
}

bool	Converter::isDouble(void)
{
	std::string	const specialType[3] = {"-inf", "+inf", "nan"};

	for (int i = 0; i < 3; i++)
	{
		if (_UserInput == specialType[i])
		{
			this->_specialType = true;
			return (true);
		}
	}
	if (isNumber() == false)
		return (false);
	return (true);
}
