/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 00:25:46 by cnascime          #+#    #+#             */
/*   Updated: 2024/07/15 05:48:24 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <cstdlib>

Base *generate(void) {
	std::srand(static_cast<unsigned>(time(0)));
	//! Testar se na 42 precisa ser std::time! APAGAR
	Base	*pointer = NULL;
	switch (std::rand() % 3) {
		case 0:
			pointer = new A();
			std::cout << "Classe A." << std::endl;
			break;
		case 1:
			pointer = new B();
			std::cout << "Classe B." << std::endl;
			break;
		case 2:
			pointer = new C();
			std::cout << "Classe C." << std::endl;
			break;
		default:
			break;
	};
	return (pointer);
};

// Use dynamic_cast if you don't know the type of the pointed/referenced object.
void	identify(Base *p) {
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "Classe A." << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "Classe B." << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "Classe C." << std::endl;
	else
		std::cout << "Classe D[esconhecida]." << std::endl;	
};

// Does not work with if statements because in this case it'll
// return a reference to the object, not a boolean expression.
void	identify(Base &p) {
	try {
		void(dynamic_cast<A&>(p));
		std::cout << "Classe A." << std::endl;
		return ;
	}
	catch (...) {};
	try {
		void(dynamic_cast<B&>(p));
		std::cout << "Classe B." << std::endl;
		return ;
	}
	catch (...) {};
	try {
		void(dynamic_cast<C&>(p));
		std::cout << "Classe C." << std::endl;
		return ;
	}
	catch (...) {};
};

int	main(void) {
	Base	*mystery = generate();

	identify(*mystery);
	identify(mystery);
	delete mystery;
};
