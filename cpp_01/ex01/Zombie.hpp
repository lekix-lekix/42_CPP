/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:47:20 by lekix             #+#    #+#             */
/*   Updated: 2025/01/15 16:48:08 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>

class Zombie
{
private:
    std::string _name;
public:
    Zombie(void);
    ~Zombie(void);
    void setName(std::string name);
    void announce(void);
};

Zombie *zombieHorde(int N, std::string name);

#endif