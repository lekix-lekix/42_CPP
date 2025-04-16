/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:08:17 by kipouliq          #+#    #+#             */
/*   Updated: 2025/04/16 12:43:55 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AllClasses.hpp"
#include "../include/utils.h"

void identify(Base* p)
{
    A *ptr = dynamic_cast<A *>(p);
    B *ptr2 = dynamic_cast<B *>(p);
    C *ptr3 = dynamic_cast<C *>(p);

    if (ptr != NULL)
        std::cout << "A\n";
    if (ptr2 != NULL)
        std::cout << "B\n";
    if (ptr3 != NULL)
        std::cout << "C\n";
}

void identify(Base& p)
{
    try
    {
        A& ref = dynamic_cast<A&>(p);
        (void) ref;
        std::cout << "A\n";
        return ;
    }
    catch(std::exception &e) {}
    try
    {
        B& ref2 = dynamic_cast<B&>(p);
        (void) ref2;
        std::cout << "B\n";
        return ;
    }
    catch(std::exception &e) {}
    try
    {
        C& ref3 = dynamic_cast<C&>(p);
        (void) ref3;
        std::cout << "C\n";
        return ;
    }
    catch(std::exception &e) {}
}

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
                break;

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
