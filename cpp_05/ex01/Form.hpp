/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:38:41 by kipouliq          #+#    #+#             */
/*   Updated: 2025/04/08 15:44:35 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "./Bureaucrat.hpp"

class Form
{
    private:
        std::string _name;
        bool        _signed;
        const int   _sign_grade;
        const int   _exec_grade;

    public:
        Form(void);
        ~Form(void);
        Form(const Form & other);
        Form & operator=(const Form & other);

        std::string     getName(void);
        int             getGrade(void);

        void            beSigned(Bureaucrat const & signer);
};

std::ostream & operator<<(std::ostream & o, Form const &src);

#endif