/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:23:42 by kipouliq          #+#    #+#             */
/*   Updated: 2025/01/30 18:22:52 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap(), FragTrap(), ScavTrap()
{
    std::cout << "DiamondTrap default constructor called" << std::endl;
    this->_hit_pts = 100;
    this->_atk_dmg = 30;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
    std::cout << "DiamondTrap " << name << " is born!" << std::endl;
    this->_name = name;
    this->_hit_pts = 100;
    this->_atk_dmg = 30;
}

DiamondTrap::DiamondTrap(DiamondTrap &rhs)
{
    *this = rhs;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap &rhs)
{
    this->_name = rhs._name;
    this->_hit_pts = rhs._hit_pts;
    this->_nrg_pts = rhs._nrg_pts;
    this->_atk_dmg = rhs._atk_dmg;
    return *this;
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << "DiamondTrap default destructor called" << std::endl;
}

void DiamondTrap::whoAmI(void)
{
    std::cout << "My parent name is " << ClapTrap::getName() << " and my name is " << this->_name << std::endl;
}
