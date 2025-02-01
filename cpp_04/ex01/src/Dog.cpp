/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:26:15 by kipouliq          #+#    #+#             */
/*   Updated: 2025/02/01 17:20:45 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog(void) : Animal()
{
    this->setType("Dog");
    this->_my_brain = new Brain();
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(Dog const &rhs) : Animal(rhs)
{
    *this = rhs;
}

Dog::~Dog(void)
{
    delete this->_my_brain;
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
