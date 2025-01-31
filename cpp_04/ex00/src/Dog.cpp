/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:26:15 by kipouliq          #+#    #+#             */
/*   Updated: 2025/01/31 18:48:45 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog(void)
{
    this->setType("Dog");
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(Dog const &rhs)
{
    *this = rhs;
}

Dog::~Dog(void)
{
    std::cout << "Dog default constructor called" << std::endl;
}

Dog &Dog::operator=(Dog const &rhs)
{
    this->setType(rhs.getType());
    return *this;
}

void Dog::makeSound(void) const
{
    std::cout << "Woof woof !" << std::endl;
}
