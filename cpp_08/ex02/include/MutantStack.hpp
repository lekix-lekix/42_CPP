/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 20:14:02 by lekix             #+#    #+#             */
/*   Updated: 2025/04/22 17:27:35 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
    public:
        MutantStack(void);
        ~MutantStack(void);
        MutantStack(MutantStack const & other);
        MutantStack(Container const & other);
        MutantStack const &operator=(MutantStack const & rhs);
        MutantStack const &operator=(Container const & rhs);
              
        typedef typename MutantStack::stack::container_type::iterator iterator;
        
        iterator begin() {return this->c.begin();}
        iterator end()   {return this->c.end();}
        iterator next()  {return this->c.next();}
        iterator prev()   {return this->c.prev();}  
};

template<typename T, typename Container>
MutantStack<T, Container>::MutantStack(void)
{
}

template<typename T, typename Container>
MutantStack<T, Container>::~MutantStack(void)
{
}

template<typename T, typename Container>
MutantStack<T, Container>::MutantStack(MutantStack const & other)
{
    *this = other;
}

template<typename T, typename Container>
MutantStack<T, Container>::MutantStack(Container const & other)
{
    *this = other;
}

template<typename T, typename Container>
MutantStack<T, Container> const & MutantStack<T, Container>::operator=(MutantStack const & rhs)
{
    this->c = rhs.c;
}

template<typename T, typename Container>
MutantStack<T, Container> const & MutantStack<T, Container>::operator=(Container const & rhs)
{
    this->c = Container(rhs);
    return *this;
}

#endif