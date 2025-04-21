/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 20:14:02 by lekix             #+#    #+#             */
/*   Updated: 2025/04/21 21:37:02 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

template<class T, class Container=std::stack<T>>
class MutantStack : public std::stack<T>
{
    private:

    public:
        MutantStack(void);
        ~MutantStack(void);
        MutantStack(MutantStack const & other);
        MutantStack &operator=(MutantStack const & rhs);
};


template<class T, class Container=std::stack<T>>
MutantStack<T>::MutantStack()
{

}

#endif