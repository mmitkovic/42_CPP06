/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitkovi <mmitkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 17:19:25 by mmitkovi          #+#    #+#             */
/*   Updated: 2026/02/25 17:19:26 by mmitkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {
    Data d;
    d.s1 = "Hello";
    d.num = 42;
    d.s2 = "World!";

    uintptr_t raw = Serializer::serialize(&d);
    std::cout << "Serialization: " << raw << std::endl;

    Data *ptr = Serializer::deserialize(raw);
    std::cout << "Deserialization: " << ptr << std::endl;
    std::cout << ptr->s1 << std::endl;
    std::cout << ptr->num << std::endl;
    std::cout << ptr->s2 << std::endl;

    uintptr_t badRaw = raw + 4;
    Data *badPtr = Serializer::deserialize(badRaw);

    if (&d == ptr) {
        std::cout << "Succes: addresses match! "
        << "( "
        << &d << " = " << ptr
        << " )"
        << std::endl;
    }
    else
        std::cout << "Error: addresses don't match" << std::endl;

    if (&d == badPtr) {
        std::cout << "Succes: addresses match! "
        << "( "
        << &d << " = " << ptr
        << " )"
        << std::endl;
    }
    else {
        std::cout << "Error: the addresses don't match"
        << "( "
        << &d << " = " << badPtr
        << " )"
        << std::endl;
    }

    return 0;
}