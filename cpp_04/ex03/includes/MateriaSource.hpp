/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:32:39 by kipouliq          #+#    #+#             */
/*   Updated: 2025/02/05 18:19:11 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria *_stock[4];

    public:
        MateriaSource(void);
        MateriaSource(MateriaSource const &rhs);
        ~MateriaSource(void);
        MateriaSource &operator=(MateriaSource const &rhs);

        void learnMateria(AMateria *m);
        AMateria *createMateria(std::string const &type);
};

#endif