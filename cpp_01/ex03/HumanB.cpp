/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:43:55 by kipouliq          #+#    #+#             */
/*   Updated: 2025/01/16 14:24:55 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
    this->_weapon_ptr = NULL;
    std::cout << "Human " << name << " is born with his/her bare hands!" << std::endl;
}

HumanB::~HumanB(void)
{
    std::cout << "Human " << this->_name << " has been destroyed!" << std::endl;
}

void HumanB::attack(void)
{
    if (!this->_weapon_ptr)
    {
        std::cout << this->_name << " enters a bare knuckle fight! BAM!" << std::endl;
        return ;
    }
    std::cout << this->_name << " attacks with his/her " << this->_weapon_ptr->getType() << " !" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->_weapon_ptr = &weapon;
}