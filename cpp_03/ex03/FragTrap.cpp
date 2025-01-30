/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:19:07 by lekix             #+#    #+#             */
/*   Updated: 2025/01/30 17:25:54 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
    std::cout << "FragTrap default constructor called" << std::endl;
    this->_hit_pts = 100;
    this->_nrg_pts = 100;
    this->_atk_dmg = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "FragTrap " << name << " is born!" << std::endl;
    this->_hit_pts = 100;
    this->_nrg_pts = 100;
    this->_atk_dmg = 30;
}

FragTrap::FragTrap(FragTrap &rhs) : ClapTrap(rhs)
{
    *this = rhs;
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap " << this->_name << " is dead !" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &rhs)
{
    this->_name = rhs._name;
    this->_hit_pts = rhs._hit_pts;
    this->_nrg_pts = rhs._nrg_pts;
    this->_atk_dmg = rhs._atk_dmg;
    return *this;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "a positive high fives request on the standard output" << std::endl;
}
