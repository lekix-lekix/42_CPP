/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:06:39 by kipouliq          #+#    #+#             */
/*   Updated: 2025/04/17 14:18:39 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <new>
#include <exception>
#include <iostream>

template<typename T>
class Array
{
    private:
        unsigned int _size;
        T            *_content;
    
    public:
        Array(void);
        Array(unsigned int n);
        ~Array(void);
        Array(Array const & other);

        Array &operator=(Array const & rhs);
        T     &operator[](unsigned int i);

        unsigned int size(void) {return (this->_size);}

    class OobException : public std::exception
    {
        public:
            const char *what(void) const throw();
    };
};

template<typename T>
Array<T>::Array(void) : _size(0)
{
    try
    {
        this->_content = new T[this->_size];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

template<typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
    try
    {
        this->_content = new T[this->_size];
        for (unsigned int i = 0; i < this->_size; i++)
            this->_content[i] = T();
    }
    catch(const std::bad_alloc& e)
    {
        std::cerr << e.what() << '\n';
    }
}

template<typename T>
Array<T>::~Array(void)
{
    delete [] this->_content;
}

template<typename T>
Array<T>::Array(Array const & other)
{
    *this = other;
}

template<typename T>
Array<T> & Array<T>::operator=(Array<T> const & other)
{
    this->_size = other._size;
    delete [] this->_content;
    try
    {
        this->_content = new T[this->_size];
        for (unsigned int i = 0; i < this->_size; i++)
            this->_content[i] = other._content[i];
        return *this;
    }
    catch(const std::bad_alloc& e)
    {
        std::cerr << e.what() << '\n';
    }
    return *this;
}

template<typename T>
T & Array<T>::operator[](unsigned int i)
{
    if (i < 0 || this->_size == 0 || i > this->_size - 1)
        throw OobException();
    return this->_content[i];
}

template<typename T>
const char * Array<T>::OobException::what(void) const throw()
{
    return ("Array exception : out of bounds\n");
}

#endif