/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:52:06 by kipouliq          #+#    #+#             */
/*   Updated: 2025/02/17 17:13:50 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat(void) : Animal()
{
    this->setType("Cat");
    this->_my_brain = new Brain();
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(Cat const &rhs) : Animal(rhs)
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
    Brain *brain_cpy = new Brain();

    *brain_cpy = *rhs._my_brain;
    this->_my_brain = brain_cpy;
    this->setType(rhs.getType());
    return *this;
}

void Cat::makeSound(void) const
{
    std::cout << "Meow meow fellas!" << std::endl;
}
