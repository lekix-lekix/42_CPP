/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:17:47 by lekix             #+#    #+#             */
/*   Updated: 2025/02/02 18:53:12 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP
#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria
{
    public:
        Ice(void);
        Ice(Ice const &rhs);
        ~Ice(void);
        Ice &operator=(Ice const &rhs);

        AMateria *clone(void) const;
        void use(ICharacter &target);
};

#endif