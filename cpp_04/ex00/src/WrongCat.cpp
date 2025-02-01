/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:32:33 by lekix             #+#    #+#             */
/*   Updated: 2025/02/01 15:44:20 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{
    std::cout << "Wrong Cat default constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat &rhs) : WrongAnimal(rhs)
{
    *this = rhs;    
}

WrongCat::~WrongCat()
{
    std::cout << "Wrong Cat default destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat &rhs)
{
    this->setType(rhs.getType());
    return *this;
}

void WrongCat::makeSound(void) const
{
    std::cout << "WoofMeowMoo! Huh weird" << std::endl;
}