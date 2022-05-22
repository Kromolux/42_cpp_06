/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 10:27:56 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/22 23:34:42 by rkaufman         ###   ########.fr       */
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
	this->_charOverflow = false;
	this->_intOverflow = false;
	this->_floatOverflow = false;
	this->_doubleOverflow = false;
	this->_myChar = ' ';
	this->_myInt = 0;
	this->_myFloat = 0.0f;
	this->_myDouble = 0.0;
	this->_precision = 1;
}

void	Converter::convert(void)
{
	this->_type = getDataType();
	long int	tmpLongInt;

	switch (this->_type)
	{
	case TYPE_CHAR:
		this->_typeAsString = "char\n";
		this->_myChar = _UserInput[0];
		this->_myInt = static_cast<int>(_myChar);
		this->_myFloat = static_cast<float>(_myChar);
		this->_myDouble = static_cast<double>(_myChar);
		break;
	case TYPE_INT:
		this->_typeAsString = "int\n";
		tmpLongInt = atol(_UserInput.c_str());
		if (_UserInput.length() > 11 || tmpLongInt > std::numeric_limits<int>::max() || tmpLongInt < std::numeric_limits<int>::min())
		{
			_charOverflow = true;
			_intOverflow = true;
			_floatOverflow = true;
			_doubleOverflow = true;
		}
		if (tmpLongInt > std::numeric_limits<char>::max() || tmpLongInt < std::numeric_limits<char>::min())
			_charOverflow = true;
		this->_myInt = atoi(_UserInput.c_str());
		this->_myChar = static_cast<char>(_myInt);
		this->_myFloat = static_cast<float>(_myInt);
		this->_myDouble = static_cast<double>(_myInt);
		break;
	case TYPE_FLOAT:
		this->_typeAsString = "float\n";
		this->_myFloat = static_cast<float>(std::strtod(_UserInput.c_str(), NULL));
		if (errno == ERANGE)
		{
			_charOverflow = true;
			_intOverflow = true;
			_floatOverflow = true;
		}
		tmpLongInt = static_cast<long>(_myFloat);
		if (_UserInput.length() > 11 || tmpLongInt > std::numeric_limits<int>::max() || tmpLongInt < std::numeric_limits<int>::min())
			_intOverflow = true;
		if (tmpLongInt > std::numeric_limits<char>::max() || tmpLongInt < std::numeric_limits<char>::min())
			_charOverflow = true;
		this->_myChar = static_cast<char>(_myFloat);
		this->_myInt = static_cast<int>(_myFloat);
		this->_myDouble = static_cast<double>(_myFloat);
		break;
	case TYPE_DOUBLE:
		this->_typeAsString = "double\n";
		this->_myDouble = std::strtod(_UserInput.c_str(), NULL);
		if (errno == ERANGE)
		{
			_charOverflow = true;
			_intOverflow = true;
			_floatOverflow = true;
			_doubleOverflow = true;
			break;
		}
		tmpLongInt = static_cast<long>(_myDouble);
		if (_UserInput.length() > 11 || tmpLongInt > std::numeric_limits<int>::max() || tmpLongInt < std::numeric_limits<int>::min())
			_intOverflow = true;
		if (tmpLongInt > std::numeric_limits<char>::max() || tmpLongInt < std::numeric_limits<char>::min())
			_charOverflow = true;
		this->_myFloat = static_cast<float>(_myDouble);
		this->_myChar = static_cast<char>(_myDouble);
		this->_myInt = static_cast<int>(_myDouble);
		break;
	case TYPE_INVALID:
		this->_typeAsString = "invalid type\n";
		break;
	default:
		this->_typeAsString = "ERROR!\n";
		break;
	}
}

int	Converter::getDataType(void)
{
	if (_UserInput.length() == 0)
		return (TYPE_INVALID);
	if (_UserInput.length() == 1)
	{
		if (isdigit(_UserInput[0]) == true)
			return (TYPE_INT);
		return (TYPE_CHAR);
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
	int		pointPos = -1;

	for (unsigned long i = 1; _UserInput[i]; i++)
	{
		if (_UserInput[i] == '.')
		{
			if(point == false)
			{
				point = true;
				pointPos = static_cast<int>(i);
			}
			else
				return (false);
		}
		else if (isdigit(_UserInput[i]) == false && (_UserInput[i] != 'f' || (_UserInput[i] == 'f' && (_UserInput.length() - 1) > i)))
			return (false);
	}
	if (point)
		this->_precision = static_cast<int>(_UserInput.length()) - pointPos - 1;
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
	std::string	const specialType[4] = {"inff", "-inff", "+inff", "nanf"};

	for (unsigned long i = 0; i < 4; i++)
	{
		if (_UserInput == specialType[i])
		{
			this->_specialType = true;
			return (true);
		}
	}
	if (isNumber() && _UserInput[_UserInput.length() - 1] == 'f')
	{
		if (this->_precision > 1)
			this->_precision--;
		return (true);
	}
	return (false);
}

bool	Converter::isDouble(void)
{
	std::string	const specialType[4] = {"inf", "-inf", "+inf", "nan"};

	for (int i = 0; i < 4; i++)
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

void	Converter::getChar(std::ostream & o) const
{
	if (this->_type == TYPE_INVALID)
	{
		o << COLOR_RED << "invalid type" << COLOR_DEFAULT;
		return ;
	}
	if (_specialType == true || _charOverflow == true)
		o << COLOR_RED << "impossible" << COLOR_DEFAULT;
	else if (isprint(_myChar) == false)
		o << COLOR_BLUE << "not displayable" << COLOR_DEFAULT;
	else
		o << COLOR_GREEN << "'" << _myChar << "'" << COLOR_DEFAULT;
}

void	Converter::getInt(std::ostream & o) const
{
	if (this->_type == TYPE_INVALID)
	{
		o << COLOR_RED << "invalid type" << COLOR_DEFAULT;
		return ;
	}
	if (_specialType == true || _intOverflow == true)
		o << COLOR_RED << "impossible" << COLOR_DEFAULT;
	else
		o << COLOR_GREEN << _myInt << COLOR_DEFAULT;
}

void	Converter::getFloat(std::ostream & o) const
{
	if (this->_type == TYPE_INVALID)
	{
		o << COLOR_RED << "invalid type" << COLOR_DEFAULT;
		return ;
	}
	if (_floatOverflow == true)
		o << COLOR_RED << "impossible" << COLOR_DEFAULT;
	else
		o	<< COLOR_GREEN << this->_myFloat << "f" << COLOR_DEFAULT;
}

void	Converter::getDouble(std::ostream & o) const
{
	if (this->_type == TYPE_INVALID)
	{
		o << COLOR_RED << "invalid type" << COLOR_DEFAULT;
		return ;
	}
	if (_doubleOverflow == true)
		o << COLOR_RED << "impossible" << COLOR_DEFAULT;
	else
	o	<< COLOR_GREEN << this->_myDouble << COLOR_DEFAULT;
}

void	Converter::getTypeString(std::ostream & o) const
{
	if (this->_type == TYPE_INVALID)
	{
		o << COLOR_RED << this->_typeAsString << COLOR_DEFAULT;
		return ;
	}
	o	<< COLOR_BLUE << this->_typeAsString << COLOR_DEFAULT;
}

bool	Converter::getSpecialType(void) const
{
	return (this->_specialType);
}

int	Converter::getPrecision(void) const
{
	return (this->_precision);
}

std::ostream & operator<<(std::ostream & o, Converter const & obj)
{
	o << "type   : ";	obj.getTypeString(o);
	if (obj.getSpecialType())
		o << COLOR_MAGENTA << "-- special type --\n" << COLOR_DEFAULT;

	std::cout << std::fixed << std::setprecision(obj.getPrecision());
	o	<< "char   : ";	obj.getChar(o);		o	<< std::endl;
	o	<< "int    : ";	obj.getInt(o);		o	<< std::endl;
	o	<< "float  : ";	obj.getFloat(o);	o	<< std::endl;
	o	<< "double : ";	obj.getDouble(o);	o	<< std::endl;
	return (o);
}