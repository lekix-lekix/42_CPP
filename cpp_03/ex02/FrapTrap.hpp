/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FrapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:14:13 by lekix             #+#    #+#             */
/*   Updated: 2025/01/29 17:29:31 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : public ClapTrap
{
public:
    FragTrap(std::string name);
    FragTrap(FragTrap &rhs);
    ~FragTrap(void);
    FragTrap &operator=(FragTrap const &rhs);

    void highFivesGuys(void);
};

#endif