/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:59:37 by lekix             #+#    #+#             */
/*   Updated: 2025/01/15 15:26:13 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->_name = name;
    std::cout << name << " created !" << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << "BANG ! " << this->_name << " killed ! \"zbleeuargg~\"" << std::endl;
}

void Zombie::announce(void)
{
    std::cout << this->_name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}