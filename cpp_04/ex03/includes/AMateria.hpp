/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:39:28 by lekix             #+#    #+#             */
/*   Updated: 2025/02/02 19:23:51 by lekix            ###   ########.fr       */
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

    public:
        AMateria(void);
        AMateria(AMateria const &rhs);
        virtual ~AMateria(void);
        AMateria &operator=(AMateria const &rhs);

        AMateria(std::string const &type);

        std::string const &getType(void) const;

        virtual AMateria *clone() const = 0;
        virtual void use(ICharacter &target);
};

#endif