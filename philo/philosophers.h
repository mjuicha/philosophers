/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:18:10 by mjuicha           #+#    #+#             */
/*   Updated: 2024/11/23 17:37:37 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>

#define FAILURE 0
#define SUCCESS 1

typedef struct s_data t_data;

typedef struct s_philo
{
    pthread_t           monitor;
    pthread_t           *philosophers;
    pthread_mutex_t     *forks;
    pthread_mutex_t     _can_take;
    pthread_mutex_t     _print;
    pthread_mutex_t     _meal;
    pthread_mutex_t     _death;
    pthread_mutex_t     _dead_flag;
    pthread_mutex_t     _test;
    pthread_mutex_t     _one_philo;
    int                 philo_nb;
    int                 t_die;
    int                 t_eat;
    int                 is_died;
    int                 t_sleep;
    int                 stop;
    int                 nb_of_meals;
    long                start_time;
    t_data              *data;
}               t_philo;

typedef struct s_data
{
    long        last_meal;
    int         id;
    int         right_fork;
    int         left_fork;
    int         still_eat;
    int         ate;
    t_philo     *philo;
}               t_data;


int     ft_atoi(const char *str);
int     is_valid_input(int ac, char **av, t_philo *philo);
#endif