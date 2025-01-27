/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 19:43:24 by lekix             #+#    #+#             */
/*   Updated: 2025/01/27 20:12:29 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    // private:

    public:
        ScavTrap(std::string name);
        ScavTrap(ScavTrap &rhs);
        ~ScavTrap(void);
        ScavTrap &operator=(ScavTrap const &rhs);
};

#endif