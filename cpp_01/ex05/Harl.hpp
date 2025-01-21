/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:02:39 by kipouliq          #+#    #+#             */
/*   Updated: 2025/01/21 16:33:29 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP
#include <iostream>


class Harl
{
private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);

public:
    Harl(void);
    ~Harl(void);
    void complain(std::string level);
};

typedef void (Harl::*Harl_func) (void);

typedef struct s_func
{
    std::string func_name;
    Harl_func   func_ptr;
} t_func;



#endif