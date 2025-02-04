/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:45:40 by lekix             #+#    #+#             */
/*   Updated: 2025/02/04 18:04:26 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"

AMateria::AMateria(void) : _equipped(false)
{
    std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(AMateria const &rhs)
{
    *this = rhs;
}

AMateria::~AMateria(void)
{
    std::cout << "AMateria destructor called" << std::endl;
}

AMateria &AMateria::operator=(AMateria const &rhs)
{
    this->_equipped = rhs._equipped;
    this->_type = rhs._type;
    return *this;
}

AMateria::AMateria(std::string const &type) : _type(type), _equipped(false)
{
    std::cout << "AMateria string constructor called" << std::endl;
}

bool AMateria::getEquipStatus(void) const
{
    return this->_equipped;
}

std::string const &AMateria::getType(void) const
{
    return this->_type;
}

void AMateria::use(ICharacter &target)
{
    (void) target;
    std::cout << "This function should be overridden" << std::endl;
}