/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:14:13 by lekix             #+#    #+#             */
/*   Updated: 2025/01/30 17:04:05 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : virtual public ClapTrap
{
public:
    FragTrap(void);
    FragTrap(FragTrap &rhs);
    ~FragTrap(void);
    FragTrap &operator=(FragTrap const &rhs);

    FragTrap(std::string name);
    
    void highFivesGuys(void);
};

#endif