/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:52:06 by kipouliq          #+#    #+#             */
/*   Updated: 2025/02/01 18:51:00 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat(void) : AAnimal()
{
    this->setType("Cat");
    this->_my_brain = new Brain();
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(Cat const &rhs) : AAnimal(rhs)
{
    *this = rhs;    
}

Cat::~Cat(void)
{
    delete this->_my_brain;
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
