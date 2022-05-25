/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 10:22:09 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/22 23:35:36 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CONVERTER_HPP
# define CONVERTER_HPP
# include <iostream>
# include <limits>
# include <iomanip>
# include <cstdlib>
# include <cerrno>
# include "colors.h"

typedef enum e_type {
	TYPE_INVALID = -1,
	TYPE_CHAR = 0,
	TYPE_INT = 1,
	TYPE_FLOAT = 2,
	TYPE_DOUBLE = 3
}			t_type;

class	Converter
{
	public:

		Converter(char const *);
		Converter(Converter const & input);
		Converter const & operator=(Converter const & input);
		~Converter(void);
	
		void				convert(void);

		void				getChar(std::ostream & o) const;
		void				getInt(std::ostream & o) const;
		void				getFloat(std::ostream & o) const;
		void				getDouble(std::ostream & o) const;
		void				getTypeString(std::ostream & o) const;

		bool				getSpecialType(void) const;
		int					getPrecision(void) const;

	protected:

	private:

		void				initValues(void);

		int					getDataType(void);
		bool				isNumber(void);
		bool				isInt(void);
		bool				isFloat(void);
		bool				isDouble(void);
		
		int					_type;
		std::string			_typeAsString;

		bool				_specialType;
		bool				_charOverflow;
		bool				_intOverflow;
		bool				_floatOverflow;
		bool				_doubleOverflow;
		
		std::string	const	_UserInput;
		char				_myChar;
		int					_myInt;
		float				_myFloat;
		double				_myDouble;

		int					_precision;
};

std::ostream & operator<<(std::ostream & o, Converter const & obj);

#endif