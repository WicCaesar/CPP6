/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 22:29:55 by cnascime          #+#    #+#             */
/*   Updated: 2024/07/14 22:50:42 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Data {
	public:
		Data(void);
		Data(int value);
		Data(const Data &copy);
		Data &operator=(const Data &copy);
		~Data(void);
		int	value;		
};
