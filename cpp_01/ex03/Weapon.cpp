/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:33:33 by lekix             #+#    #+#             */
/*   Updated: 2025/01/16 14:16:23 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
    std::cout << "Weapon " << type << " created!" << std::endl;
}

Weapon::~Weapon(void)
{
    std::cout << "Weapon " << this->getType() << " destroyed!" << std::endl;
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
