/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:50:30 by kipouliq          #+#    #+#             */
/*   Updated: 2025/04/21 19:17:44 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>

class Span
{
    private:
        unsigned int          _size_max;
        std::vector<int>      _numbers;
        
    public:
        Span(void);
        ~Span(void);
        Span(unsigned int size_max);
        Span(Span const & other);
        Span const &operator=(Span const & rhs);

        void        addNumber(int nb);
        void        addNumbers(int (*func)());
        int         shortestSpan(void);
        int         longestSpan(void);
        void        printSpan(void);

    class SpanFull : public std::exception
    {
        public:
            const char *what(void) const throw();
    };

    class EmptyContainer : public std::exception
    {
        public:
            const char *what(void) const throw();
    };
};

#endif