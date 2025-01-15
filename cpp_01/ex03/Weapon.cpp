/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:33:33 by lekix             #+#    #+#             */
/*   Updated: 2025/01/15 17:52:12 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void)
{
    std::cout << "Weapon created!" << std::endl;
}

Weapon::~Weapon(void)
{
    std::cout << "Weapon destroyed!" << std::endl;
}

std::string const &Weapon::getType(void)
{
    const std::string &type_ref = this->_type;
    return type_ref;
}

void Weapon::setType(std::string new_type)
{
    this->_type = new_type;
}
