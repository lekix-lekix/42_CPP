/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:27:02 by lekix             #+#    #+#             */
/*   Updated: 2025/04/09 18:57:05 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "../include/AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        std::string _target;
        void        launch_form_exec(std::string target) const;

    public:
        RobotomyRequestForm();
        ~RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm & other);
        RobotomyRequestForm & operator=(const RobotomyRequestForm & other);
};

#endif