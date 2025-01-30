/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:21:50 by lekix             #+#    #+#             */
/*   Updated: 2025/01/30 16:14:03 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>

class ClapTrap
{
    protected:
        std::string _name;
        int _hit_pts;
        int _nrg_pts;
        int _atk_dmg;
        bool canDo(void) const;
        
    public:
        ClapTrap(void);
        ClapTrap(ClapTrap &rhs);
        ~ClapTrap(void);
        ClapTrap &operator=(ClapTrap const &rhs);
        
        ClapTrap(std::string name);
        
        void attack(const std::string &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        std::string getName(void);
        int getHP(void);
        int getNRG(void);
        int getATK(void);
};

#endif