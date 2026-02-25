/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitkovi <mmitkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 17:20:26 by mmitkovi          #+#    #+#             */
/*   Updated: 2026/02/25 17:20:27 by mmitkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void identify(Base& p) {
    try {
        A& a = dynamic_cast<A&>(p);
        std::cout << "A: " << &a << " = " << &p << std::endl;
        return ;
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    try {
        B& b = dynamic_cast<B&>(p);
        std::cout << "B: " << &b << " = " << &p << std::endl;
        return ;
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    try {
        C& c = dynamic_cast<C&>(p);
        std::cout << "C: " << &c << " = " << &p <<std::endl;
        return ;
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

Base *generate() {
    Base *g;
    switch (rand() % 3) {
        case 0:
            return g = new A();
        case 1:
            return  g = new B();
        case 2:
            return g = new C();
    }
    return NULL;
}

int main()
{
    srand(time(NULL));
    Base *ptr = generate();
    Base &ptrRef = *generate();
    identify(ptr);
    identify(ptrRef);

    delete &ptrRef;
    delete ptr;
}