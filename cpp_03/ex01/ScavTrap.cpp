/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 19:45:58 by lekix             #+#    #+#             */
/*   Updated: 2025/01/27 20:23:42 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap::ClapTrap(name)
{
    std::cout << "ScavTrap constructor called. He's named " << name << std::endl;
    this->_hit_pts = 100;
    this->_nrg_pts = 50;
    this->_atk_dmg = 20;
}

ScavTrap::ScavTrap(ScavTrap &rhs) : ClapTrap::ClapTrap(rhs)
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
    this->_name = rhs._name;
    this->_hit_pts = rhs._hit_pts;
    this->_nrg_pts = rhs._nrg_pts;
    this->_atk_dmg = rhs._atk_dmg;
    return *this;
}
    
// ScavTrap(ScavTrap &rhs);
// ~ScavTrap(void);
// ScavTrap &operator=(ScavTrap & rhs);