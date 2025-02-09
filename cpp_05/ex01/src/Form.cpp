/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:12:59 by lekix             #+#    #+#             */
/*   Updated: 2025/02/09 16:25:00 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

Form::Form(void) : _name("Default form"), _signed(false), _sign_grade(150), _exec_grade(150)
{
    std::cout << "Form default constructor called" << std::endl;
}

Form::Form(Form const &rhs) : _name(rhs._name), _signed(rhs._signed), _sign_grade(rhs._sign_grade), _exec_grade(rhs._exec_grade)
{
    std::cout << "Form cctor called" << std::endl;
}

Form::~Form(void)
{
    std::cout << "Form destructor called" << std::endl;
}

Form &Form::operator=(Form const &rhs)
{
    this->_signed = rhs._signed;
    std::cout << "Everything is const. Only copying signed status" << std::endl;
    return *this;
}

Form::Form(std::string name, int sign_grade, int exec_grade) : _name(name), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
    try
    {
        if (sign_grade > 150 || exec_grade > 150)
            throw GradeTooLowException();
        else if (sign_grade < 1 || exec_grade < 1)
            throw GradeTooHighException();
        std::cout << "A new form has been successfully created !" << std::endl;
    }
    catch (GradeTooHighException &e)
    {
        throw e;
    }
    catch (GradeTooLowException &e)
    {
        throw e;
    }
}

std::string const &Form::getName(void) const
{
    return this->_name;
}

bool const &Form::getSignedStatus(void) const
{
    return this->_signed;
}

int const &Form::getSignGrade(void) const
{
    return this->_sign_grade;
}

int const &Form::getExecGrade(void) const
{
    return this->_exec_grade;
}

void Form::beSigned(Bureaucrat const &bcrat)
{
    try
    {
        if (bcrat.getGrade() > this->_sign_grade)
            throw GradeTooLowException();
        this->_signed = true;
    }
    catch(const GradeTooLowException& e)
    {
        throw e;
    }
}

