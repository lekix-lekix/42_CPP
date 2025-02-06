/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:28:42 by lekix             #+#    #+#             */
/*   Updated: 2025/02/06 12:02:29 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _hit_pts(10), _nrg_pts(10), _atk_dmg(0)
{
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &rhs)
{
    *this = rhs;
    std::cout << "ClapTrap Copy constructor called. He's named " << this->_name << std::endl;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs)
{
    this->_name = rhs._name;
    this->_hit_pts = rhs._hit_pts;
    this->_nrg_pts = rhs._nrg_pts;
    this->_atk_dmg = rhs._atk_dmg;
    return *this;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_pts(10), _nrg_pts(10), _atk_dmg(0)
{
    std::cout << "ClapTrap constructor called. He's named " << this->_name << std::endl;
}

std::string ClapTrap::getName(void)
{
    return this->_name;
}

int ClapTrap::getHP(void)
{
    return this->_hit_pts;
}

int ClapTrap::getNRG(void)
{
    return this->_nrg_pts;
}

int ClapTrap::getATK(void)
{
    return this->_atk_dmg;
}

bool ClapTrap::canDo(void) const
{
    if (!this->_hit_pts)
    {
        std::cout << "ClapTrap " << this->_name << " has no HP left and can't do anything." << std::endl;
        return false;
    }
    if (!this->_nrg_pts)
    {
        std::cout << "ClapTrap " << this->_name << " has no energy left and can't do anything." << std::endl;
        return false;
    }
    return true;
}

void ClapTrap::attack(const std::string &target)
{
    if (!this->canDo())
        return;
    std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_atk_dmg << " points of damage!" << std::endl;
    this->_nrg_pts -= 1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (!this->_hit_pts)
    {
        std::cout << "ClapTrap " << this->_name << " don't have any HP to lose.. but his feelings are hurt.";
        return;
    }
    std::cout << "ClapTrap " << this->_name << " loses " << amount << " HP!" << std::endl;
    this->_hit_pts -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (!this->canDo())
        return;
    std::cout << "ClapTrap " << this->_name << " got back " << amount << " HP!" << std::endl;
    this->_hit_pts += amount;
    this->_nrg_pts -= 1;
}
