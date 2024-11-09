/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:03:06 by mjuicha           #+#    #+#             */
/*   Updated: 2024/11/09 20:51:31 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H
#endif

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
int     ft_atoi(const char *str);

typedef struct  s_info
{
    pthread_mutex_t     *forks;
    pthread_t           *threads;
}            t_info;

typedef struct s_phil t_phil;


typedef struct  s_philo
{
    t_info          *info;
    t_phil         *philos;
    int             right;
    int             left;
    int             philo_nb;
    int             is_time;
    int             is_died;
    long            start_time;
    long            last_meal;
    pthread_mutex_t mutex;
    int             t_die;
    int             t_eat;
    int             t_sleep;
    int             nb_of_meals;
}               t_philo;

typedef struct  s_phil
{
    int             id;
    int             fake_id;
    int             right;
    int             left;
    int             nb_philo;
    t_philo         *philoss;
    t_info          *info;
}            t_phil;

