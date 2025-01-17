/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:12:19 by lekix             #+#    #+#             */
/*   Updated: 2025/01/16 13:59:16 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon_ref(weapon)
{
    std::cout << "Human " << name << " is born with a " << _weapon_ref.getType() << std::endl;
}

HumanA::~HumanA(void)
{
    std::cout << "Human " << this->_name << " has been destroyed!" << std::endl;
}

void HumanA::attack(void)
{
    std::cout << this->_name << " attacks with his/her " << this->_weapon_ref.getType() << std::endl;
}
