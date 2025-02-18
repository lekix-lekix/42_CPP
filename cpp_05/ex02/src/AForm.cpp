/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:12:59 by lekix             #+#    #+#             */
/*   Updated: 2025/02/10 14:54:00 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"

AForm::AForm(void) : _name("Default form"), _signed(false), _sign_grade(150), _exec_grade(150)
{
    std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(AForm const &rhs) : _name(rhs._name), _signed(rhs._signed), _sign_grade(rhs._sign_grade), _exec_grade(rhs._exec_grade)
{
    std::cout << "AForm cctor called" << std::endl;
}

AForm::~AForm(void)
{
    std::cout << "AForm destructor called" << std::endl;
}

AForm &AForm::operator=(AForm const &rhs)
{
    this->_signed = rhs._signed;
    std::cout << "Everything is const. Only copying signed status" << std::endl;
    return *this;
}

AForm::AForm(std::string name, int sign_grade, int exec_grade) : _name(name), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
    try
    {
        if (sign_grade > 150 || exec_grade > 150)
            throw GradeTooLowException();
        else if (sign_grade < 1 || exec_grade < 1)
            throw GradeTooHighException();
        std::cout << "A new Aform has been successfully created !" << std::endl;
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

std::string const &AForm::getName(void) const
{
    return this->_name;
}

bool const &AForm::getSignedStatus(void) const
{
    return this->_signed;
}

int const &AForm::getSignGrade(void) const
{
    return this->_sign_grade;
}

int const &AForm::getExecGrade(void) const
{
    return this->_exec_grade;
}

void AForm::beSigned(Bureaucrat const &bcrat)
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

