/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:19:32 by mjuicha           #+#    #+#             */
/*   Updated: 2024/11/23 17:52:31 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long    get_time(void);

long    time_(t_philo *philo);
void    philo_msg(t_data *data, char *msg)
{
    pthread_mutex_lock(&(data->philo->_print));
    if (data->philo->is_died == 0)
        printf("%ld %d %s\n", time_(data->philo), data->id, msg);
    pthread_mutex_unlock(&(data->philo->_print));
}

int    init_threads(t_philo *philo)
{
    philo->forks = malloc(sizeof(pthread_mutex_t) * philo->philo_nb);
    philo->philosophers = malloc(sizeof(pthread_t) * philo->philo_nb);
    if (!philo->forks || !philo->philosophers)
        return (FAILURE);
    return (SUCCESS);
}

int     init_mutex(t_philo *philo)
{
    int     i;

    i = 0;
    while (i < philo->philo_nb)
    {
        pthread_mutex_init(&(philo->forks[i]), NULL);
        i++;
    }
    pthread_mutex_init(&(philo->_meal), NULL);
    pthread_mutex_init(&(philo->_can_take), NULL);
    pthread_mutex_init(&(philo->_print), NULL);
    pthread_mutex_init(&(philo->_death), NULL);
    pthread_mutex_init(&(philo->_dead_flag), NULL);
    pthread_mutex_init(&(philo->_test), NULL);
    pthread_mutex_init(&(philo->_one_philo), NULL);
    return (SUCCESS);
}

void    ft_usleep(t_philo *philo, long time)
{
    long    start_time;

    start_time = philo->start_time;
    while (get_time() - start_time < time)
        usleep(100);
}

long    time_(t_philo *philo)
{
    return (get_time() - philo->start_time);
}

void    take_right_forks(t_data *data)
{
    pthread_mutex_lock(&(data->philo->forks[data->right_fork]));
    philo_msg(data, "has taken a fork");
}
void    take_left_forks(t_data *data)
{
    pthread_mutex_lock(&(data->philo->forks[data->left_fork]));
    philo_msg(data, "has taken a fork");
}

void    put_forks(t_data *data)
{
    pthread_mutex_unlock(&(data->philo->forks[data->right_fork]));
    pthread_mutex_unlock(&(data->philo->forks[data->left_fork]));
}

void    sleep_(t_data *data)
{
    philo_msg(data, "is sleeping");
    usleep(data->philo->t_sleep * 1000);
}

void    think_(t_data *data)
{
    philo_msg(data, "is thinking");
}

void    eat_(t_data *data)
{
    philo_msg(data, "is eating");
    pthread_mutex_lock(&(data->philo->_meal));
    data->last_meal = get_time();
    data->ate++;
    pthread_mutex_unlock(&(data->philo->_meal));
    usleep(data->philo->t_eat * 1000);
}

void    *check_deeath(t_philo *philo)
{
    pthread_mutex_lock(&(philo->_test));
    printf("\033[32m%d\033[0m\n", philo->is_died);
    pthread_mutex_unlock(&(philo->_test));
    return (NULL);
}
void    *philosophers(void *arg)
{
    t_data  *data = (t_data *)arg;
    if (data->id % 2 == 0)
        ft_usleep(data->philo, data->philo->t_eat);
    while (data->philo->is_died == 0 && data->still_eat == 1)
    {
        take_right_forks(data);
        if (data->philo->philo_nb == 1)
        {
            usleep(data->philo->t_die * 1000);
            philo_msg(data, "is died");
            break ;
        }
        take_left_forks(data);
        // check_deeath(data->philo);
        eat_(data);
        // check_deeath(data->philo);
        put_forks(data);
        // check_deeath(data->philo);
        sleep_(data);
        think_(data);
        // check_deeath(data->philo);
    }
    return (NULL);
}

void    *check_death(void *arg)
{
    t_data  *data = (t_data *)arg;
    while (data->philo->is_died == 0 && data->philo->stop == 0)
    {
        if ((data->last_meal + data->philo->t_die) < get_time() && data->philo->philo_nb != 1)
        {
            pthread_mutex_lock(&(data->philo->_print));
            data->philo->is_died = 1;
            printf("%ld %d died\n", time_(data->philo), data->id);
            pthread_mutex_unlock(&(data->philo->_print));
        }
        usleep(100);
    }
    return (NULL);
}


void *more_eat(void *arg)
{
    t_data  *data = (t_data *)arg;
    while (data->still_eat == 1)
    {
        if (data->ate == data->philo->nb_of_meals)
        {
            pthread_mutex_lock(&(data->philo->_test));
            data->still_eat = 0;
            data->philo->stop++;
            pthread_mutex_unlock(&(data->philo->_test));
            break ;
        }
    }
    return (NULL);
}

void    run(t_philo *philo, t_data *data)
{
    int     i;
    pthread_t  monitor;
    pthread_t  monitor2;
    

    i = 0;
    while (i < philo->philo_nb)
    {
        pthread_create(&(philo->philosophers[i]), NULL, &philosophers, &(data[i]));
        pthread_create(&(monitor), NULL, &check_death, &(data[i]));
        if (philo->nb_of_meals != -1)
            pthread_create(&(monitor2), NULL, &more_eat, &(data[i]));
        pthread_detach(monitor);
        i++;
        usleep(100);
    }
}
void    join(t_philo *philo)
{
    int     i;

    i = 0;
    while (i < philo->philo_nb)
    {
        pthread_join(philo->philosophers[i], NULL);
        i++;
    }
    if (philo->nb_of_meals != -1)
        pthread_join(philo->monitor, NULL);
}

long    get_time(void)
{
    struct timeval  tv;
    long            time;

    gettimeofday(&tv, NULL);
    time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
    return (time);
}

t_data    *get_data(t_philo *philo)
{
    t_data      *data;
    int         i;
    
    data = malloc(sizeof(t_data) * philo->philo_nb);
    if (!data)
        return (NULL);
    i = 0;
    philo->start_time = get_time();
    philo->is_died = 0;
    philo->stop = 0;
    while (i < philo->philo_nb)
    {
        data[i].id = i + 1;
        data[i].last_meal = philo->start_time;
        data[i].right_fork = i;
        data[i].philo = philo;
        data[i].still_eat = 1;
        data[i].ate = 0;
        if (i == 0)
            data[i].left_fork = philo->philo_nb - 1;
        else
            data[i].left_fork = i - 1;
        i++;
    }
    return (data);
}

void    ft_philo(t_philo *philo)
{
    t_data    *data;
    init_threads(philo);
    init_mutex(philo);
    data = get_data(philo);
    run(philo, data);
    join(philo);
}

int main(int ac, char **av)
{
    t_philo *philo = malloc(sizeof(t_philo));
    if (!philo)
        return (1);
    if (!is_valid_input(ac, av, philo))
        return (1);
    ft_philo(philo);
    free(philo);
    return (0);
}
