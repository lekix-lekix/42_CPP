/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:08:17 by kipouliq          #+#    #+#             */
/*   Updated: 2025/04/15 18:19:35 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AllClasses.hpp"
#include "../include/utils.h"

Base *generate(void)
{
    int nb = rand() % 3;
    std::cout << "nb = " << nb << "\n";
    Base *ptr = NULL;

    try
    {
        switch (nb)
        {
            case 0:
                ptr = new A;
                break;
        
            case 1:
                ptr = new B;

            case 2:
                ptr = new C;

            default:
                break;
        }
        return ptr;
    }
    catch (std::exception &e)
    {
        e.what();
    }
    return NULL;
}