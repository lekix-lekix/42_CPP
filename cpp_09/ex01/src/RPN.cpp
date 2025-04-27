/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 20:30:44 by lekix             #+#    #+#             */
/*   Updated: 2025/04/27 21:15:05 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"

RPN::RPN(void) {}

RPN::~RPN(void) {}

RPN::RPN(RPN const & other) { *this = other; }

RPN const & RPN::operator=(RPN const & rhs)
{
    this->_rpn_stack = rhs._rpn_stack;
    return *this;
}

int RPN::error(void)
{
    std::cout << "Error\n";
    return -1;
}

int RPN::calculate(int f_term, int s_term, char op)
{
    if (op == '+')
        return f_term + s_term;
    else if (op == '-')
        return f_term - s_term;
    else if (op == '*')
        return f_term * s_term;
    else
        return f_term / s_term;
}

int RPN::loadStackAndCalculate(std::string to_calculate)
{
    if (!to_calculate.length())
        return error();
        
    std::istringstream iss(to_calculate);
    std::string        expr;

    while (iss >> expr)
    {
        if (expr.find_first_not_of("0123456789-+*/") != expr.npos || expr.length() > 1)
            return error();
        if (isalnum(expr[0]))
            this->_rpn_stack.push(atoi(expr.c_str()));
        else if (expr.find_first_not_of("+-*/") != expr.npos)
            return error();
        else
        {
            if (this->_rpn_stack.size() <= 1)
                return error();
            int second_term = this->_rpn_stack.top();
            this->_rpn_stack.pop();
            int first_term = this->_rpn_stack.top();
            this->_rpn_stack.pop();
            if ((!first_term || !second_term) && expr[0] == '/')
                return error();
            this->_rpn_stack.push(this->calculate(first_term, second_term, expr[0]));
        }
    }
    if (this->_rpn_stack.size() > 1)
        return error();
    std::cout << _rpn_stack.top() << "\n";
    return (0);
}