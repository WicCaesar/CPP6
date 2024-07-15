/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 04:10:27 by cnascime          #+#    #+#             */
/*   Updated: 2024/07/14 16:47:35 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {
};

ScalarConverter::ScalarConverter(const ScalarConverter &copy) {
	if (this != &copy)
		*this = copy;
};

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy) {
	*this = copy;
	return (*this);
};

ScalarConverter::~ScalarConverter(void) {
};

void	ScalarConverter::convert(const std::string &input) {
	int	type = getType(input);
	switch (type) {
		case (CHAR):
			displayChar(input);
			break;
		case (INT):
			displayInt(input);
			break;
		case (FLOAT):
			displayFloat(input);
			break;
		case (DOUBLE):
			displayDouble(input);
			break;
		case (LITERAL):
			displayLiteral(input);
			break;
		default:
			displayError();
	};
	return;
};

// Little parser to identify the type of the literal.
// npos represents the greatest possible value for an element of type size_t.
e_type	getType(const std::string &input) {
	if (isLiteral(input) == true)
		return (LITERAL);
	else if (input.length() == 1 && !isdigit(input[0]))
		return (CHAR);
	else if (isInt(input) == true)
		return (INT);
	else if (isFloat(input) == true)
		return (FLOAT);
	/*else if ((input.at(0) == '+' || input.at(0) == '-' || isdigit(input.at(0)))
		&& input.find('.') != std::string::npos
		&& (input.at(input.length() - 1) == 'f' || input.at(input.length() - 1) == 'F'))
		return (FLOAT);*/
	else if (isDouble(input) == true)
		return (DOUBLE);
	/*else if ((input.at(0) == '+' || input.at(0) == '-' || isdigit(input.at(0)))
		&& input.find('.') != std::string::npos)
		return (DOUBLE);*/
	return (ERROR);
};

bool	isInt(std::string input) {
	size_t		i = 0;
	int			number;
	long int	longnumber;

	if (input.at(0) == '+' || input.at(0) == '-')
		i++;
	if (!input[i])
		return (false);
	while (i < input.length()) {
		if (!isdigit(input.at(i)))
			return (false);
		i++;
	};
// istringstream is a stream class to operate on strings.
// A stream is an object that can send or receive data, character by character.
// The std::istringstream reads from the string (as opposed to writing on it).
	std::istringstream stream(input);
	std::istringstream longstream(input);
	if ((stream >> number).fail()) // Sets a flag if the extraction fails.
		return (false);
	longstream >> longnumber; // No fail check 'cause I want to check the limit.
	if (longnumber < std::numeric_limits<int>::min() // The C++ way of checking.
		|| longnumber > std::numeric_limits<int>::max())
		return (false);
	return (true);
};

bool	isFloat(std::string input) {
	size_t	i = 0;
	float	number;
	int		points = 0;
	int		efs = 0;

	if (input.at(0) == '+' || input.at(0) == '-')
		i++;
	if (!input[i])
		return (false);
	while (input[i]) {
		if (!isdigit(input.at(i)) && input.at(i) != '.'
			&& input.at(i) != 'f' && input.at(i) != 'F')
			return (false);
		if (input.at(i) == '.')
			points++;
		if (input.at(i) == 'f' || input.at(i) == 'F')
			efs++;
		if (points > 1 || efs > 1)
			return (false);
		if ((input.at(i) == 'f' || input.at(i) == 'F') && input[i + 1] != '\0')
			return (false);
		i++;
	};
	if (points != 1 || efs != 1)
		return (false);
	// Erases the 'f' or 'F' at the end.
	std::istringstream stream(input.erase(input.length() - 1));
	if ((stream >> number).fail())
		return (false);
	if (number < std::numeric_limits<float>::min()
		|| number > std::numeric_limits<float>::max())
		return (false);
	return (true);
};

bool	isDouble(std::string input) {
	size_t	i = 0;
	double	number;
	int		points = 0;

	if (input.at(0) == '+' || input.at(0) == '-')
		i++;
	if (!input[i])
		return (false);
	while (i < input.length()) {
		if (!isdigit(input.at(i)) && input.at(i) != '.')
			return (false);
		if (input.at(i) == '.')
			points++;
		if (points > 1)
			return (false);
		i++;
	};
	if (points != 1)
		return (false);
	std::istringstream stream(input.erase(input.length() - 1));
	if ((stream >> number).fail())
		return (false);
	if (number < std::numeric_limits<double>::min()
		|| number > std::numeric_limits<double>::max())
		return (false);
	return (true);
};

bool	isLiteral(std::string input) {
	std::string possibilities[8] = {"nan", "inf", "+inf", "-inf",
		"nanf", "inff", "+inff", "-inff"};

	for (int i = 0; i < 8; i++) {
		if (input.compare(possibilities[i]) == 0)
			return (true);
	};
	return (false);
};

// In case of an impossible conversion.
void	displayError(void) {
	std::cout << "char: impossible\n"
			  << "int: impossible\n"
			  << "float: impossible\n"
			  << "double: impossible" << std::endl;
};

// Static cast is used to convert the reference to the desired type.
// Opposed to dynamic cast, which is used to convert pointers and references
// to classes up and down the hierarchy. Example: base class pointer to derived.
void	displayChar(const std::string &input) {
	unsigned char	reference = input.at(0);

	if (reference > 127)
		std::cout << "char: impossible\n";
	else if (isprint(reference) == false)
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: '" << reference << "'\n";
	std::cout << "int: " << static_cast<int>(reference) << "\n"
	<< "float: " << static_cast<float>(reference) << ".0f\n"
	<< "double: " << static_cast<double>(reference) << ".0" << std::endl;
};

void	displayInt(const std::string &input) {
	int	reference = std::atoi(input.c_str());

	if (reference < 0 || reference > 255)
		std::cout << "char: impossible\n";
	else if (isprint(reference) == false)
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: '" << static_cast<char>(reference) << "'\n";
	std::cout << "int: " << reference << "\n"
	<< "float: " << static_cast<float>(reference) << ".0f\n"
	<< "double: " << static_cast<double>(reference) << ".0" << std::endl;
};

void	displayFloat(const std::string &input) {
	double	reference = std::strtod(input.c_str(), NULL);

	if (reference < 0 || reference > 255 || isLiteral(input) == true)
		std::cout << "char: impossible\n";
	else if (isprint(reference) == false)
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: '" << static_cast<char>(reference) << "'\n";

	if (reference < INT_MIN || reference > INT_MAX)
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << static_cast<int>(reference) << "\n";

	if (reference == static_cast<int>(reference))
		std::cout << "float: " << reference << ".0f\n";
	else
		std::cout << "float: " << reference << "f\n";

	if (reference == static_cast<int>(reference))
		std::cout << "double: " << static_cast<double>(reference) << ".0" << std::endl;
	else
		std::cout << "double: " << static_cast<double>(reference) << std::endl;
};

void	displayDouble(const std::string &input) {
	double	reference = std::strtod(input.c_str(), NULL);

	if (reference < -128 || reference > 127 || isLiteral(input) == true)
		std::cout << "char: impossible\n";
	else if (isprint(reference) == false)
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: '" << static_cast<char>(reference) << "'\n";

	if (reference < INT_MIN || reference > INT_MAX)
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << static_cast<int>(reference) << "\n";

	if (reference < static_cast<double>(std::numeric_limits<float>::min())
		|| reference > static_cast<double>(std::numeric_limits<float>::max()))
		std::cout << "float: impossible\n";
	else if (static_cast<float>(reference) == static_cast<int>(reference))
		std::cout << "float: " << static_cast<float>(reference) << ".0f\n";
	else
		std::cout << "float: " << static_cast<float>(reference) << "f\n";

	if (reference == static_cast<int>(reference))
		std::cout << "double: " << reference << ".0" << std::endl;
	else
		std::cout << "double: " << reference << std::endl;
};

void	displayLiteral(std::string input) {
	std::cout << "char: impossible\n"
			  << "int: impossible\n";
	if (input == "nanf" || input == "inff"
		|| input == "+inff" || input == "-inff") {
			std::cout << "float: " << input << "\n"
			<< "double: " << input.erase(input.length() - 1) << std::endl;
	} else {
		std::cout << "float: " << input << "f\n"
		<< "double: " << input << std::endl;
	};
};
