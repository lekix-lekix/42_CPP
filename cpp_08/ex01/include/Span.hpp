/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:50:30 by kipouliq          #+#    #+#             */
/*   Updated: 2025/04/23 12:46:51 by kipouliq         ###   ########.fr       */
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
        Span(Span const & other);
        Span const &operator=(Span const & rhs);
        
        Span(unsigned int size_max);
        
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