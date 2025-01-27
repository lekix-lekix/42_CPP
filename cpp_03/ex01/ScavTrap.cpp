/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 19:45:58 by lekix             #+#    #+#             */
/*   Updated: 2025/01/27 20:13:57 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap::ClapTrap(name)
{
    std::cout << "ScavTrap constructor called. He's named " << name << std::endl;  
}

ScavTrap::ScavTrap(ScavTrap &rhs)
{
    *this = rhs;
    // std::cout << "Copy constructor called. He's named " << this->_name << std::endl;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs)
{
    this->_name =         
}
// ScavTrap(ScavTrap &rhs);
// ~ScavTrap(void);
// ScavTrap &operator=(ScavTrap & rhs);