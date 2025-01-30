/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:16:49 by kipouliq          #+#    #+#             */
/*   Updated: 2025/01/30 18:19:22 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP
#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
    std::string _name;

public:
    DiamondTrap(void);
    DiamondTrap(DiamondTrap &rhs);
    ~DiamondTrap(void);
    DiamondTrap &operator=(DiamondTrap &rhs);

    DiamondTrap(std::string name);

    void whoAmI(void);

};

#endif