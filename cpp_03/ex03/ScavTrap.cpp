/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 19:45:58 by lekix             #+#    #+#             */
/*   Updated: 2025/01/30 17:26:02 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
    std::cout << "ScavTrap default constructor called" << std::endl;
    this->_hit_pts = 100;
    this->_nrg_pts = 50;
    this->_atk_dmg = 20;
}

ScavTrap::ScavTrap(ScavTrap &rhs) : ClapTrap(rhs)
{
    *this = rhs;
    std::cout << "ScavTrap copy constructor called. He's named " << this->_name << std::endl;
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

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "ScavTrap constructor called. He's named " << name << std::endl;
    this->_hit_pts = 100;
    this->_nrg_pts = 50;
    this->_atk_dmg = 20;
}

void ScavTrap::attack(std::string const &target)
{
    if (!this->canDo())
        return;
    std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_atk_dmg << " points of damage!" << std::endl;
    this->_nrg_pts -= 1;
}

void ScavTrap::guardGate(void)
{
    std::cout << "Scavtrap " << this->_name << " now in Gate Keeper mode." << std::endl;
}
