/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:27:02 by lekix             #+#    #+#             */
/*   Updated: 2025/04/09 16:56:50 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "../include/AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        void launch_form_exec(std::string target) const;

    public:
        RobotomyRequestForm();
        ~RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm & other);
        RobotomyRequestForm & operator=(const RobotomyRequestForm & other);
};

#endif