/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:57:42 by lekix             #+#    #+#             */
/*   Updated: 2025/01/15 16:48:19 by lekix            ###   ########.fr       */
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
    Zombie(std::string name);
    ~Zombie(void);
    void announce(void);
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif