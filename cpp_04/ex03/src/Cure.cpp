/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:39:13 by lekix             #+#    #+#             */
/*   Updated: 2025/02/02 18:55:26 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
    std::cout << "Cure default constructor called" << std::endl;    
}

Cure::Cure(Cure const &rhs) : AMateria(rhs)
{
    *this = rhs;
}

Cure::~Cure(void)
{
    std::cout << "Cure destructor called" << std::endl;
}

Cure &Cure::operator=(Cure const &rhs)
{
    this->_type = rhs._type;
    return *this;
}

AMateria *Cure::clone(void) const
{
    return new Cure(*this);
}

void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
