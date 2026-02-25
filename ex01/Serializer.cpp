/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitkovi <mmitkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 17:19:36 by mmitkovi          #+#    #+#             */
/*   Updated: 2026/02/25 18:07:38 by mmitkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <string>

Serializer::Serializer() {}
Serializer::Serializer(const Serializer& src) { (void)src; }
Serializer& Serializer::operator=(const Serializer& src) 
{
	(void)src;
	return *this;
}
Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data* ptr) 
{
    uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
    return raw;
}

Data* Serializer::deserialize(uintptr_t raw) 
{
    Data* data = reinterpret_cast<Data*>(raw);
    return data;
}