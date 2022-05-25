/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 22:49:47 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/22 23:21:56 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BASE_HPP
# define BASE_HPP

class Base
{
	public:
		virtual ~Base(void) {}
	protected:

	private:
};

class A : public Base
{};

class B : public Base
{};

class C : public Base
{};

#endif