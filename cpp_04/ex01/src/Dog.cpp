/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:26:15 by kipouliq          #+#    #+#             */
/*   Updated: 2025/02/17 17:15:34 by kipouliq         ###   ########.fr       */
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
    Brain *brain_cpy = new Brain();

    *brain_cpy = *rhs._my_brain;
    this->_my_brain = brain_cpy;
    this->setType(rhs.getType());
    return *this;
}

void Dog::makeSound(void) const
{
    std::cout << "Woof woof !" << std::endl;
}
