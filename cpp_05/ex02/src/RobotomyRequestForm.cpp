/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:30:28 by lekix             #+#    #+#             */
/*   Updated: 2025/04/09 17:27:08 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RobotomyRequestForm.hpp"
#include "stdlib.h"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("robotomy request", 72, 45)
{
    std::cout << "Robotomy request form created\n";
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    std::cout << "Robotomy request form destructed\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & other) : AForm(other)
{
    *this = other;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm & other)
{
    (void) other;
    return *this;
}

void RobotomyRequestForm::launch_form_exec(std::string target) const
{
    srand(time(0));
    int fail = rand() % 2;
    if (fail)
        std::cout << "Robotomy on " << target << " failed!\n";
    else
        std::cout << "*DRILLING* *BZZZ* Robotomy on " << target << " succeeded !\n";
}