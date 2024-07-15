/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 16:48:38 by cnascime          #+#    #+#             */
/*   Updated: 2024/07/15 05:03:03 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdint.h>
//! Testar na 42! Aqui em casa não funciona com a flag C98. APAGAR
#include "Data.hpp"

class Serializer {
	private:
		Serializer(void);
		Serializer(const Serializer &copy);
		Serializer &operator=(const Serializer &copy);
		~Serializer(void);

	public:
		static uintptr_t	serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
};
