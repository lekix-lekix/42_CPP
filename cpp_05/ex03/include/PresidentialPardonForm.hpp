/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:00:18 by lekix             #+#    #+#             */
/*   Updated: 2025/04/09 18:56:57 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "../include/AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string _target;
        void        launch_form_exec(std::string target) const;

    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        ~PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm & other);
        PresidentialPardonForm & operator=(const PresidentialPardonForm & other);
};

#endif