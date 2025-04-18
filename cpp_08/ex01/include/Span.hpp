/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:50:30 by kipouliq          #+#    #+#             */
/*   Updated: 2025/04/18 18:52:00 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <exception>

class Span
{
    private:
        unsigned int        _size_max;
        std::vector<int>    _numbers;
        
    public:
        Span(void);
        ~Span(void);
        Span(unsigned int size_max);
        Span(Span const & other);
        Span const &operator=(Span const & rhs);

        void        addNumber(int nb);
        // void        addNumbers()
        int         shortestSpan(void);
        int         longestSpan(void);

    class SpanFull : public std::exception
    {
        public:
            const char *what(void) throw();
    };
};

#endif