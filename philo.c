/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:02:38 by mjuicha           #+#    #+#             */
/*   Updated: 2024/11/07 18:15:47 by mjuicha          ###   ########.fr       */
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
    philo->philo_nbs = ft_atoi(av[1]);
    philo->t_die = ft_atoi(av[2]);
    philo->t_eat = ft_atoi(av[3]);
    philo->t_sleep = ft_atoi(av[4]);
    if (ac == 6)
        philo->nb_of_meals = ft_atoi(av[5]);
    
}
int     check_philo(t_philo *philo)
{
    if (philo->philo_nbs <= 0 || philo->t_die <= 0 || philo->t_eat <= 0 || philo->t_sleep <= 0 || philo->nb_of_meals <= 0)
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

pthread_mutex_t create_mutex()
{
    pthread_mutex_t mutex;
    pthread_mutex_init(&mutex, NULL);
    return (mutex);
}

pthread_t create_thread()
{
    pthread_t thread = malloc(sizeof(pthread_t));
    return (thread);
}

void    get_forks(t_philo *philo, int fork)
{
    // printf("ID: %d\n", philo->id);
    printf("                                                       lock: %d\n", fork);
    pthread_mutex_lock(&philo->philo_mutex[fork]);
    // printf("philo %d has taken a fork\n", philo->id);
}

int right_fork(t_philo *philo)
{
    printf("max_id: %d\n", philo->max_id);
    printf("philo->id: %d\n", philo->id);
    if (philo->id == philo->max_id)
        return (0);
    return (philo->id + 1);
}

int left_fork(t_philo *philo)
{
    return (philo->id);
}

void    *philos(void *arg)
{
    t_philo *philo = (t_philo *)arg;
    philo->right_id = right_fork(philo);
    printf("philo->right_id: %d\n", philo->right_id);
    philo->left_id = left_fork(philo);
    printf("%d <======== fork[%d] ========> %d\n", philo->left_id, philo->id, philo->right_id);
    // get_forks(philo, philo->left_id);
    // get_forks(philo, philo->right_id);
    printf("philo %d is eating\n", philo->id);
    // pthread_mutex_unlock(&philo->philo_mutex[philo->left_id]);
    // printf("                                unlock: %d\n", philo->left_id);
    // pthread_mutex_unlock(&philo->philo_mutex[philo->right_id]);
    // printf("                                unlock: %d\n", philo->right_id);
    return (NULL);
}
void ft_philo(t_philo *philo)
{
    if (!philo)
        return;
    
    philo->philo_mutex = malloc(sizeof(pthread_mutex_t) * philo->philo_nbs);
    t_philo *philosophers = malloc(sizeof(t_philo) * philo->philo_nbs);
    if (!philo->philo_mutex || !philosophers)
        return;
    
    // Initialize mutexes
    for (int i = 0; i < philo->philo_nbs; i++)
        pthread_mutex_init(&philo->philo_mutex[i], NULL);
    
    // Create threads
    for (int i = 0; i < philo->philo_nbs; i++)
    {
        philosophers[i] = *philo;         // Copy common data
        philosophers[i].id = i;           // Assign unique ID
        philosophers[i].max_id = philo->philo_nbs - 1; // Assign max ID
        philosophers[i].philo_thread = malloc(sizeof(pthread_t));
        pthread_create((philosophers[i].philo_thread), NULL, &philos, &philosophers[i]);
    }
    
    // Wait for all threads to finish
    for (int i = 0; i < philo->philo_nbs; i++)
        pthread_join(*(philosophers[i].philo_thread), NULL);

    free(philosophers);
}

int main(int ac, char **av)
{
    t_philo *philo = malloc(sizeof(t_philo));
    if (!philo)
        return (1);
    if (!is_valid_input(ac, av, philo))
        return (1);
    printf("philo_nb: %d\nt_die: %d\nt_eat: %d\nt_sleep: %d\nnb_of_meals: %d\n", philo->philo_nbs, philo->t_die, philo->t_eat, philo->t_sleep, philo->nb_of_meals);
    ft_philo(philo);
    return (0);
}