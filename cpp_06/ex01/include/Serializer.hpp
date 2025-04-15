/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:26:02 by kipouliq          #+#    #+#             */
/*   Updated: 2025/04/15 15:49:07 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include "../include/include.h"

class Serializer
{
    private:
        Serializer(void);
        ~Serializer(void);
        Serializer(Serializer const & other);
        Serializer &operator=(Serializer const & rhs);

    public:
        static uintptr_t serialize(Data *ptr);
        static Data*     deserialize(uintptr_t raw);
};

#endif