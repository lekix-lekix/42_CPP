/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 19:43:24 by lekix             #+#    #+#             */
/*   Updated: 2025/02/06 11:41:59 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap(void);
        ScavTrap(ScavTrap &rhs);
        ~ScavTrap(void);
        ScavTrap &operator=(ScavTrap const &rhs);
        
        ScavTrap(std::string name);
        
        void attack(std::string const &target);
        void guardGate(void);
};

#endif