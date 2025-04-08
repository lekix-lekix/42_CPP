/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 20:56:49 by lekix             #+#    #+#             */
/*   Updated: 2025/04/08 21:36:14 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Form.hpp"

/******** CANONICAL FORM *******/

Form::Form(void) : _name("Default form"), _signed(false), _sign_grade(150), _exec_grade(150)
{
    std::cout << "Default form constructor called\n";
}

Form::~Form(void)
{
    std::cout << "Default form destructor called\n";
}

Form::Form(const Form & other) : _name(other._name), _exec_grade(other._exec_grade), _sign_grade(other._sign_grade)
{
    *this = other;
}

Form::Form(std::string name, int sign_grade, int exec_grade) : _name(name), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
    this->_signed = false;
    if (sign_grade > 150 || exec_grade > 150)
        throw GradeTooLowException();
    else if (sign_grade < 0 || exec_grade < 0)
        throw GradeTooHighException();
}

Form &Form::operator=(const Form & other)
{
    // name and grades const
    this->_signed = other._signed;
}

std::ostream &operator<<(std::ostream & os, Form & src)
{
    std::cout << src.getName() << ", form, exec grade : " << src.getExecGrade() << ", sign grade : " << src.getSignGrade() << "\n";
}

/*******************************/

std::string Form::getName(void)
{
    return this->_name;
}

bool Form::getSignStatus(void)
{
    return this->_signed;
}

int Form::getSignGrade(void)
{
    return this->_sign_grade;
}

int Form::getExecGrade(void)
{
    return this->_exec_grade;
}

void Form::beSigned(Bureaucrat & signatory)
{
    if (this->_sign_grade <= signatory.getGrade())
        throw GradeTooLowException();
    this->_signed = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Form Exception : Grade too high\n");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Form Exception : Grade too low\n");
}
