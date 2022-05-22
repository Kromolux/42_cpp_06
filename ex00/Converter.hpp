/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 10:22:09 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/22 15:50:24 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CONVERTER_HPP
# define CONVERTER_HPP
# include <iostream>
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
	
		void	convert(void);

	protected:

	private:

		void				initValues(void);

		int					getDataType(void);
		bool				isNumber(void);
		bool				isInt(void);
		bool				isFloat(void);
		bool				isDouble(void);
	
		int					_type;

		bool				_specialType;

		std::string	const	_UserInput;
		char				_myChar;
		int					_myInt;
		float				_myFloat;
		double				_myDouble;

};

std::ostream & operator<<(std::ostream & o, Converter const & input);

#endif