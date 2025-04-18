/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:06:04 by kipouliq          #+#    #+#             */
/*   Updated: 2025/04/18 18:44:57 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"

Span::Span(void) : _size_max(0), _numbers() {}

Span::~Span(void) {}

Span::Span(unsigned int size_max) : _size_max(size_max) 
{
    _numbers.reserve(this->_size_max);
}

Span::Span(Span const & other)
{
    *this = other;
}

Span const &Span::operator=(Span const & rhs)
{
    this->_size_max = rhs._size_max;
    this->_numbers = rhs._numbers;
}

void Span::addNumber(int nb)
{
    if (this->_numbers.size() < _size_max)
    {
        this->_numbers.push_back(nb);
        
    }
    else
        throw SpanFull();
}

const char *Span::SpanFull::what(void) throw()
{
    return  ("Span exception : Span is full\n");
}

