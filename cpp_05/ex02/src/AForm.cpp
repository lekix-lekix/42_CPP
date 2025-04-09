/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 20:56:49 by lekix             #+#    #+#             */
/*   Updated: 2025/04/09 16:17:15 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"

/******** CANONICAL FORM *******/

AForm::AForm(void) : _name("Default AForm"), _signed(false), _sign_grade(150), _exec_grade(150)
{
    std::cout << "Default form constructor called\n";
}

AForm::~AForm(void)
{
    std::cout << "Default AForm destructor called\n";
}

AForm::AForm(const AForm & other) : _name(other._name), _sign_grade(other._sign_grade), _exec_grade(other._exec_grade)
{
    *this = other;
}

AForm::AForm(std::string name, int sign_grade, int exec_grade) : _name(name), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
    this->_signed = false;
    if (sign_grade > 150 || exec_grade > 150)
        throw GradeTooLowException();
    else if (sign_grade <= 0 || exec_grade <= 0)
        throw GradeTooHighException();
}

AForm &AForm::operator=(const AForm & other)
{
    // name and grades const
    this->_signed = other._signed;
    return *this;
}

std::ostream & operator<<(std::ostream & os, AForm & src)
{
    os << src.getName() << ", Aform, exec grade : " << src.getExecGrade() << ", sign grade : " << src.getSignGrade() << "\n";
    return os;
}

/*******************************/

std::string AForm::getName(void)
{
    return this->_name;
}

bool AForm::getSignStatus(void)
{
    return this->_signed;
}

int AForm::getSignGrade(void)
{
    return this->_sign_grade;
}

int AForm::getExecGrade(void)
{
    return this->_exec_grade;
}

void AForm::beSigned(Bureaucrat & signatory)
{
    if (this->_sign_grade < signatory.getGrade())
        throw GradeTooLowException();
    this->_signed = true;
    std::cout << this->_name << " has been signed!\n";
}

void AForm::execute(Bureaucrat & executor) const
{
    if (this->_exec_grade < executor.getGrade())
        throw GradeTooLowException();
    if (!this->_signed)
        throw FormNotSigned();
    this->launch_form_exec(executor.getName());
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("AForm Exception : Grade too high\n");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Form Exception : Grade too low\n");
}

const char *AForm::FormNotSigned::what() const throw()
{
    return ("Form must be signed before execution\n");
}