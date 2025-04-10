/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 20:56:49 by lekix             #+#    #+#             */
/*   Updated: 2025/04/10 14:03:54 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"

/******** CANONICAL FORM *******/

AForm::AForm(void) : _name("Default AForm"),  _target(""), _signed(false), _sign_grade(150), _exec_grade(150)
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

AForm::AForm(std::string name, std::string target, int sign_grade, int exec_grade) : _name(name), _target(target), _signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
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

std::string AForm::getTarget(void)
{
    return this->_target;
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
    else if (this->_signed)
        throw FormAlreadySigned();
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

const char *AForm::FormAlreadySigned::what() const throw()
{
    return ("Form is already signed\n");
}