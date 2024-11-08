/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:02:38 by mjuicha           #+#    #+#             */
/*   Updated: 2024/11/08 19:29:00 by mjuicha          ###   ########.fr       */
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
    if (philo->philo_nb <= 0 || philo->t_die <= 0 || philo->t_eat <= 0 || philo->t_sleep <= 0 || philo->nb_of_meals <= 0)
        return (1);
    return (0);
}

int     is_valid_input(int ac, char **av, t_philo *philo)
{
    if (ac != 5 && ac != 6)
    {
        printf("\033[31;1mError: wrong numbers of arguments\033[0m\n");
        return (0);
    }
    if (check_input(ac, av) == 0)
    {
        printf("\033[31;1mError: wrong arguments\033[0m\n");
        return (0);
    }
    philo_info(philo, ac, av);
    if (check_philo(philo))
        return (printf("\033[31;1mError: wrong arguments\033[0m\n"), 0);
    printf("\033[32;1mEverything is fine\033[0m\n");
    
    return (1);
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

void    *philo_lanch(void *arg)
{
    t_philo *philo = (t_philo *)arg;
    int i = 0;
    philo->info = create_philos(philo);
    if (!philo->info)
        printf("\x1b[31mPhilosophers Error\033[0m\n");
    printf("\x1b[32mPhilosophers created\033[0m\n");
    return (NULL);
}

void    ft_philo(t_philo *philo)
{
    philo_lanch(philo);
    // pthread_create(&thread, NULL, philo_routine, philo);
    // pthread_join(thread, NULL);   
}
int main(int ac, char **av)
{
    t_philo *philo = malloc(sizeof(t_philo));
    if (!philo)
        return (1);
    if (!is_valid_input(ac, av, philo))
        return (1);
    printf("philo_nb: %d\nt_die: %d\nt_eat: %d\nt_sleep: %d\nnb_of_meals: %d\n", philo->philo_nb, philo->t_die, philo->t_eat, philo->t_sleep, philo->nb_of_meals);
    ft_philo(philo);
    return (0);
}