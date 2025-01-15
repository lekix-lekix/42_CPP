/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:03:54 by lekix             #+#    #+#             */
/*   Updated: 2025/01/15 19:28:47 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.cpp"

class HumanA
{
private:
    std::string _name;
    Weapon &_weapon;

public:
    HumanA(std::string name, Weapon weapon);
    ~HumanA(void);
}