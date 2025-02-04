/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:39:28 by lekix             #+#    #+#             */
/*   Updated: 2025/02/04 18:03:15 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP
#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
    protected:
        std::string _type;
        bool    _equipped;

    public:
        AMateria(void);
        AMateria(AMateria const &rhs);
        virtual ~AMateria(void);
        AMateria &operator=(AMateria const &rhs);

        AMateria(std::string const &type);

        std::string const &getType(void) const;
        bool getEquipStatus(void) const;
        
        virtual AMateria *clone() const = 0;
        virtual void use(ICharacter &target);
};

#endif