/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 00:25:03 by cnascime          #+#    #+#             */
/*   Updated: 2024/07/15 00:25:05 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void) {
	Data	test(23);
	Data	*original = &test;

	uintptr_t	raw = Serializer::serialize(original);
	Data		*converted = Serializer::deserialize(raw);
	std::cout << "Original: " << original->value
			  << "\nSerializado: " << raw
			  << "\nConvertido: " << converted->value << std::endl;
	if (converted == original)
		std::cout << "Manteve o ponteiro original." << std::endl;
	else
		std::cout << "O ponteiro foi adulterado." << std::endl;
};
