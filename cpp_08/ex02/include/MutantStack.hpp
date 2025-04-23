/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 20:14:02 by lekix             #+#    #+#             */
/*   Updated: 2025/04/23 16:47:38 by kipouliq         ###   ########.fr       */
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
        MutantStack(void) {};
        ~MutantStack(void) {};
        MutantStack(MutantStack const & other) { *this = other; };
        MutantStack(Container const & other) { *this = other; };
        MutantStack const &operator=(MutantStack const & rhs) { return (this->c = rhs.c), *this; };
        MutantStack const &operator=(Container const & rhs) { return (this->c = Container(rhs), *this); };
              
        typedef typename MutantStack::stack::container_type::iterator               iterator;
        typedef typename MutantStack::stack::container_type::reverse_iterator       reverse_iterator;
        
        iterator begin()          { return this->c.begin(); }
        iterator end()            { return this->c.end(); }
        reverse_iterator rbegin() { return this->c.rbegin(); }
        reverse_iterator rend()   { return this->c.rend(); }
};

#endif