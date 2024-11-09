/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:02:38 by mjuicha           #+#    #+#             */
/*   Updated: 2024/11/09 20:49:32 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int     is_space(char c)
{
    if (c == 32 || (c >= 9 && c <= 13))
        return (1);
    return (0);
}

int     check_input(int ac, char **av)
{
    int i;
    int j;

    i = 1;
    while (i < ac)
    {
        j = 0;
        while (av[i][j])
        {
            while (is_space(av[i][j]))
                j++;
            if (av[i][j] == '+')
                j++;
            while (av[i][j] >= '0' && av[i][j] <= '9')
                j++;
            if (av[i][j] == 0)
                break;
            else
                return (0);
        }
        i++;
    }
    return (1);
}

void    philo_info(t_philo *philo, int ac, char **av)
{
    if (!av)
        return ;
    philo->philo_nb = ft_atoi(av[1]);
    philo->t_die = ft_atoi(av[2]);
    philo->t_eat = ft_atoi(av[3]);
    philo->t_sleep = ft_atoi(av[4]);
    if (ac == 6)
        philo->nb_of_meals = ft_atoi(av[5]);
    
}
int     check_philo(t_philo *philo)
{
    if (philo->philo_nb <= 0 || philo->t_die <= 0 || philo->t_eat <= 0 || philo->t_sleep <= 0)
        return (1);
    return (0);
}

int     is_valid_input(int ac, char **av, t_philo *philo)
{
    if (ac != 5 && ac != 6)
    {
        printf("Error: wrong numbers of arguments\n");
        return (0);
    }
    if (check_input(ac, av) == 0)
    {
        printf("Error: wrong arguments\n");
        return (0);
    }
    philo_info(philo, ac, av);
    if (check_philo(philo))
        return (printf("Error: wrong arguments\n"), 0);
    return (1);
}

long    get_time(void)
{
    struct timeval  tv;
    gettimeofday(&tv, NULL);
    return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

t_info  *create_philos(t_philo *philo)
{
    t_info *info = malloc(sizeof(t_info));
    if (!info)
        return (NULL);
    info->forks = malloc(sizeof(pthread_mutex_t) * philo->philo_nb);
    info->threads = malloc(sizeof(pthread_t) * philo->philo_nb);
    if (!info->threads || !info->forks)
        return (NULL);
    philo->is_time = 0;
    philo->is_died = 0;
    int i = 0;
    pthread_t thread;
    while (i < philo->philo_nb)
    {
        info->threads[i] = thread;
        pthread_mutex_init(&info->forks[i], NULL);
        i++;
    }
    return (info);
}

void    philo_lanch(void *arg)
{
    t_philo *philo = (t_philo *)arg;
    int i = 0;
    philo->info = create_philos(philo);
    pthread_mutex_t n_mutex;
    philo->mutex = n_mutex;
    pthread_mutex_init(&philo->mutex, NULL);
    if (!philo->info)
        printf("Philosophers Error\n");
}

int    right_fork(t_phil *philos)
{
    return (philos->id);
}

int    left_fork(t_phil *philos)
{
    if (philos->id == 0)
        return (philos->nb_philo - 1);
    return (philos->id - 1);
}
void    philo_msg(t_phil *philos, char *msg)
{
    printf("%ld %d %s\n", get_time() - philos->philoss->start_time, philos->fake_id, msg);
}
void    take_fork(t_phil *philos)
{
    pthread_mutex_lock(&philos->info->forks[philos->right]);
    pthread_mutex_lock(&philos->info->forks[philos->left]);
    if (philos->philoss->is_time == 0)
    {
        philos->philoss->start_time = get_time();
        philos->philoss->is_time = 1;
    }
    philo_msg(philos, "has taken a fork");
    if (philos->philoss->philo_nb == 1)
    {
        usleep(philos->philoss->t_die * 1000);
        philos->philoss->is_died = 1;
    }
    philo_msg(philos, "has taken a fork");
    // printf("\x1b[34;1mLOCKED MUTEX ARE : %d and %d\033[0m\n", philos->right, philos->left);
    // printf("Philosopher %d has taken a fork\n", philos->fake_id);
    // printf("Philosopher %d has taken a fork\n", philos->fake_id);
}
void    down_fork(t_phil *philos)
{
    pthread_mutex_unlock(&philos->info->forks[philos->right]);
    pthread_mutex_unlock(&philos->info->forks[philos->left]);
    // printf("\x1b[31;1mUNLOCKED MUTEX ARE : %d and %d\033[0m\n", philos->right, philos->left);
}
void    eating(t_phil *philos)
{
    philo_msg(philos, "is eating");
    philos->philoss->last_meal = get_time();
    usleep(philos->philoss->t_eat * 1000);
}

void    sleeping(t_phil *philos)
{
    philo_msg(philos, "is sleeping");
    usleep(philos->philoss->t_sleep * 1000);
    philo_msg(philos, "is thinking");
}
void    *philoso(void *arg)
{
    t_phil *philos = (t_phil *)arg;
    while (!philos->philoss->is_died)
    {
        t_phil *philos = (t_phil *)arg;
        philos->right = right_fork(philos);
        philos->left = left_fork(philos);
        take_fork(philos);
        eating(philos);
        down_fork(philos);
        sleeping(philos);
    }
    return (NULL);
}

void    *check_death(void *arg)
{
    t_phil *philos = (t_phil *)arg;
    while (!philos->philoss->is_died)
    {
        if (get_time() - philos->philoss->last_meal > philos->philoss->t_die)
        {
            philo_msg(philos, "died");
            philos->philoss->is_died = 1;
            break;
        }
    }
    return (NULL);
}

void    ft_philo(t_philo *philo)
{
    philo_lanch(philo);
    int i = 0;
    t_phil  *philos = malloc(sizeof(t_phil) * philo->philo_nb);
    while (i < philo->philo_nb)
    {
        philos[i].id = i;
        philos[i].fake_id = i + 1;
        philos[i].info = philo->info;
        philos[i].philoss = philo;
        philos[i].nb_philo = philo->philo_nb;
        pthread_create(&philo->info->threads[i], NULL, &philoso, (void *)&philos[i]);
        pthread_create(&philo->info->threads[i], NULL, &check_death, (void *)&philos[i]);
        i++;
    }
    i = 0;
    while (i < philo->philo_nb)
    {
        pthread_join(philo->info->threads[i], NULL);
        i++;
    }
}
int main(int ac, char **av)
{
    t_philo *philo = malloc(sizeof(t_philo));
    if (!philo)
        return (1);
    if (!is_valid_input(ac, av, philo))
        return (1);
    ft_philo(philo);
    return (0);
}
