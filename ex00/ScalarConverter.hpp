/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 04:02:18 by cnascime          #+#    #+#             */
/*   Updated: 2024/07/14 15:13:55 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <limits>
#include <climits>
#include <cstdlib>

enum e_type {
	ERROR,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	LITERAL
};

class ScalarConverter {
	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter &operator=(const ScalarConverter &copy);

	public:
		~ScalarConverter(void);

		static void	convert(const std::string &input);
};

e_type	getType(const std::string &input);
bool	isInt(std::string input);
bool	isFloat(std::string input);
bool	isDouble(std::string input);
bool	isLiteral(std::string input);
void	displayError(void);
void	displayChar(const std::string &input);
void	displayInt(const std::string &input);
void	displayFloat(const std::string &input);
void	displayDouble(const std::string &input);
void	displayLiteral(std::string input);
