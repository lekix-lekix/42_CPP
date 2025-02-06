/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:16:49 by kipouliq          #+#    #+#             */
/*   Updated: 2025/02/06 13:27:45 by kipouliq         ###   ########.fr       */
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

        std::string const &getName(void) const;
    
        void whoAmI(void);

};

#endif