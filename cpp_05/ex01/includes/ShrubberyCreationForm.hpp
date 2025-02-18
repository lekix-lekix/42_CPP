/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:51:22 by kipouliq          #+#    #+#             */
/*   Updated: 2025/02/10 15:01:42 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "../includes/AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
        void createAsciiTree(void);

    public:
        ShrubberyCreationForm(void);
        ShrubberyCreationForm(ShrubberyCreationForm const &rhs);
        ~ShrubberyCreationForm(void);
        ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);
};

#endif