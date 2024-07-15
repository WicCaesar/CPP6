/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 22:43:56 by cnascime          #+#    #+#             */
/*   Updated: 2024/07/14 22:50:55 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(void) {
};

Data::Data(int value) : value(value) {
};

Data::Data(const Data &copy) {
	if (this != &copy)
		*this = copy;
};

Data &Data::operator=(const Data &copy) {
	this->value = copy.value;
	return (*this);
};

Data::~Data(void) {
};
