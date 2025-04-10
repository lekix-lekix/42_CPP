/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:57:22 by lekix             #+#    #+#             */
/*   Updated: 2025/04/10 13:07:26 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATIONFORM_HPP
# define SHRUBBERY_CREATIONFORM_HPP

#include <iostream>
#include <fstream>
#include <exception>
#include "../include/AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
        void launch_form_exec(std::string target) const;

    public:
        ShrubberyCreationForm();
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm & other);
        ShrubberyCreationForm(std::string const target);
        ShrubberyCreationForm & operator=(const ShrubberyCreationForm & other);

    class ShrubberyFileError : public std::exception
    {
        public:
            const char *what(void) const throw();
    };
};

#endif