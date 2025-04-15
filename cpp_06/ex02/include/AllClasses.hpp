/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AllClasses.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:07:18 by kipouliq          #+#    #+#             */
/*   Updated: 2025/04/15 18:16:12 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALLCLASSES_HPP
# define ALLCLASSES_HPP

class Base
{
    public:
        virtual ~Base(void);
};

class A : public Base
{
    public:
        ~A(void);
};

class B : public Base
{
    public:
        ~B(void);
};

class C : public Base
{
    public:
        ~C(void);
};

#endif 