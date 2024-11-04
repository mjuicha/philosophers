/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:03:06 by mjuicha           #+#    #+#             */
/*   Updated: 2024/11/04 17:50:21 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H
#endif

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int     ft_atoi(const char *str);
typedef struct  s_philo
{
    int             philo_nb;
    int             t_die;
    int             t_eat;
    int             t_sleep;
    int             nb_of_meals;
}               t_philo;