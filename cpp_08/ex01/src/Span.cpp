/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:06:04 by kipouliq          #+#    #+#             */
/*   Updated: 2025/04/23 12:57:24 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"

Span::Span(void) : _size_max(0), _numbers(0) {}

Span::~Span(void) {}

Span::Span(unsigned int size_max) : _size_max(size_max)
{
    this->_numbers.reserve(size_max);
}

Span::Span(Span const & other)
{
    *this = other;
}

Span const &Span::operator=(Span const & rhs)
{
    this->_size_max = rhs._size_max;
    this->_numbers = rhs._numbers;
    return *this;
}

void Span::addNumber(int nb)
{
    if (this->_numbers.size() < _size_max)
        this->_numbers.push_back(nb);
    else
        throw SpanFull();
}

void Span::addNumbers(int (*func)())
{
    if (!func)
        return ;
    this->_numbers.resize(this->_size_max);
    std::generate(this->_numbers.begin(), this->_numbers.end(), func);
}

int Span::shortestSpan(void)
{
    std::vector<int> to_search = this->_numbers;
    std::vector<int>::iterator it;
    int shortest = this->longestSpan(); // will throw exception if needed
    int span;

    std::sort(to_search.begin(), to_search.end());
    for (it = to_search.begin(); it != to_search.end(); it++)
    {
        if (it + 1 != to_search.end() && (span = *(it + 1) - *it) != 0 && span < shortest)
            shortest = span;
        if (shortest == 1)
            return shortest;
    }
    return (shortest);
}

int Span::longestSpan(void)
{
    int min;
    int max;

    if (_numbers.size() == 0 || _numbers.size() == 1)
        throw EmptyContainer();
    max = *std::max_element(this->_numbers.begin(), this->_numbers.end());
    min = *std::min_element(this->_numbers.begin(), this->_numbers.end());
    return max - min;
}

void Span::printSpan(void)
{
    std::vector<int>::iterator it;

    if (_numbers.size() == 0)
        throw EmptyContainer();
    for (it = this->_numbers.begin(); it != this->_numbers.end(); it++)
        std::cout << *it << "\n";
}

const char *Span::SpanFull::what(void) const throw()
{
    return  ("Span exception : Span is full\n");
}

const char *Span::EmptyContainer::what(void) const throw()
{
    return ("Span exception : Span container is empty or contains only one number\n");
}
