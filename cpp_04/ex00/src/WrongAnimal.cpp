/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:16:16 by lekix             #+#    #+#             */
/*   Updated: 2025/02/01 15:44:16 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("Wrong Animal")
{
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &rhs)
{
    *this = rhs;
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "WrongAnimal default destructor called" << std::endl;    
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &rhs)
{
    this->_type = rhs._type;
    return *this;
}

void WrongAnimal::setType(std::string type)
{
    this->_type = type;
}

std::string WrongAnimal::getType(void) const
{
    return this->_type;
}

void WrongAnimal::makeSound(void) const
{
    std::cout << "Moooo ! Damn that sounded wrong" << std::endl;
}
