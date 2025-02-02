/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:52:06 by kipouliq          #+#    #+#             */
/*   Updated: 2025/02/01 15:25:23 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat(void) : Animal()
{
    this->setType("Cat");
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(Cat const &rhs) : Animal(rhs)
{
    *this = rhs;    
}

Cat::~Cat(void)
{
    std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(Cat const &rhs)
{
    this->setType(rhs.getType());
    return *this;
}

void Cat::makeSound(void) const
{
    std::cout << "Meow meow fellas!" << std::endl;
}
