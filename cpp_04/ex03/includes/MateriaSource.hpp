/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:32:39 by kipouliq          #+#    #+#             */
/*   Updated: 2025/02/04 18:40:48 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP
#include "AMateria.hpp"

class MateriaSource
{
    public:
        MateriaSource(void);
        MateriaSource(MateriaSource const &rhs);
        ~MateriaSource(void);
        MateriaSource &operator=(MateriaSource const &rhs);

        AMateria *learnMateria(AMateria *m);
        AMateria *createMateria(std::string const &type);
};

#endif