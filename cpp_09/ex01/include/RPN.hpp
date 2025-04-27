/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 20:21:19 by lekix             #+#    #+#             */
/*   Updated: 2025/04/27 21:01:45 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <cstdlib>
#include <iostream>
#include <sstream>

class RPN
{
    private:
        std::stack<int> _rpn_stack;

    public:
        RPN(void);
        ~RPN(void);
        RPN(RPN const & other);
        RPN const &operator=(RPN const & rhs);

        int calculate(int f_term, int s_term, char op);
        int loadStackAndCalculate(std::string to_calculate);
        int error(void);
};

#endif