/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 22:06:46 by cnascime          #+#    #+#             */
/*   Updated: 2024/07/15 05:39:36 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <cstdint>

Serializer::Serializer(void) {
};

Serializer::Serializer(const Serializer &copy) {
	if (this != &copy)
		*this = copy;
};

Serializer &Serializer::operator=(const Serializer &copy) {
	*this = copy;
	return (*this);
};

Serializer::~Serializer(void) {
};

// reinterpret_cast converts a pointer into another pointer of any type,
// no matter whether the classes are related to each other.
// Used for conversions that are inherently unsafe, riskier than static_cast.
uintptr_t	Serializer::serialize(Data *ptr) {
	if (ptr) {
		uintptr_t	raw = reinterpret_cast<uintptr_t>(ptr);
		return (raw);
	}
	std::cerr << "null" << std::endl;
	return (0);
};

Data *Serializer::deserialize(uintptr_t raw) {
	if (raw) {
		Data	*ptr = reinterpret_cast<Data*>(raw);
		return (ptr);
	}
	std::cerr << "null" << std::endl;
	return (NULL);
};
