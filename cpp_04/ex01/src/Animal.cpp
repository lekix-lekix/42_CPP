/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:11:50 by kipouliq          #+#    #+#             */
/*   Updated: 2025/02/01 16:01:00 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

Animal::Animal(void)
{
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(Animal const &rhs)
{
    *this = rhs;
}

Animal::~Animal(void)
{
    std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(Animal const &rhs)
{
    this->_type = rhs._type;
    return *this;
}

void Animal::makeSound(void) const
{
    std::cout << "Generic animal sound" << std::endl;
}

void Animal::setType(std::string const type)
{
    this->_type = type;
}

std::string Animal::getType(void) const
{   
    return this->_type;
}
