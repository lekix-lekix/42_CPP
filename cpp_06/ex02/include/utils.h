/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:06:19 by kipouliq          #+#    #+#             */
/*   Updated: 2025/04/16 11:47:33 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include "../include/AllClasses.hpp"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <exception>

Base *generate(void);
void  identify(Base* p);
void  identify(Base& p);

#endif