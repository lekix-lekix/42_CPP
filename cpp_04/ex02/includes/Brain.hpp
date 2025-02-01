/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:07:06 by lekix             #+#    #+#             */
/*   Updated: 2025/02/01 17:08:52 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>

class Brain
{
    private:
        std::string _ideas[100];

    public:
        Brain(void);
        Brain(Brain const &rhs);
        ~Brain(void);
        Brain &operator=(Brain const &rhs);
};

#endif