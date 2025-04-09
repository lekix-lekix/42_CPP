/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:00:11 by lekix             #+#    #+#             */
/*   Updated: 2025/04/09 18:59:26 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("presidential pardon", 25, 5)
{
    std::cout << "Presidential Pardon Form created\n";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("presidential pardon", 25, 5), _target(target)
{
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    std::cout << "Presidential pardon form destroyed\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & other) : AForm(other)
{
    *this = other;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm & other)
{
    (void) other;
    return *this;
}

void PresidentialPardonForm::launch_form_exec(std::string target) const
{
    std::cout << target << " has been pardoned by Zaphod Beeblebrox.\n";
}