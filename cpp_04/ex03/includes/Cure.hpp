/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:36:38 by lekix             #+#    #+#             */
/*   Updated: 2025/02/02 18:52:31 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP
#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria
{
    public:
        Cure(void);
        Cure(Cure const &rhs);
        ~Cure(void);
        Cure &operator=(Cure const &rhs);

        AMateria *clone(void) const;
        void use(ICharacter &target);
};

#endif