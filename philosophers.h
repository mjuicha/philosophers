/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:03:06 by mjuicha           #+#    #+#             */
/*   Updated: 2024/11/07 18:13:28 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H
#endif

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

int     ft_atoi(const char *str);

typedef struct  s_philo
{
    pthread_t       *philo_thread;
    pthread_mutex_t *philo_mutex;
    int             philo_nbs;
    int             max_id;
    int             id;
    int             t_die;
    int             t_eat;
    int             t_sleep;
    int             nb_of_meals;
    int             right_id;
    int             left_id;
}               t_philo;

// void    ft_philo(t_philo *philo)
// {
//     if (!philo)
//         return ;
//     philo->philo_mutex = malloc(sizeof(pthread_mutex_t) * philo->philo_nbs);
//     philo->philo_thread = malloc(sizeof(pthread_t) * philo->philo_nbs);
//     t_philo *philos = malloc(sizeof(t_philo) * philo->philo_nbs);
//     if (!philo->philo_mutex || !philo->philo_thread)
//         return ;
//     int i = 0;
//     philo->max_id = philo->philo_nbs - 1;
//     while (i < philo->philo_nbs)
//     {
//         philo->philo_mutex[i] = create_mutex();
//         // pthread_mutex_init(&philo->philo_mutex[i], NULL);
//         philo->philo_thread[i] = create_thread();
//         i++;
//     }
//     i = 0;
//     while (i < philo->philo_nbs)
//     {
//         philos[i] = *philo;
//         philos[i].id = i;
//         philos[i].philo_mutex = philo->philo_mutex;
//         philos[i].philo_thread = philo->philo_thread;
//         philo->id = i;
//         printf("THREAD %d\n", i);
//         pthread_create(&philo->philo_thread[i], NULL, &philos, &philo[i]);
//         i++;
//     }
//     i = 0;
//     while (i < philo->philo_nbs)
//     {
//         pthread_join(philo->philo_thread[i], NULL);
//         i++;
//     }
// // }