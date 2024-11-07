// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   philo.c                                            :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/11/03 17:02:38 by mjuicha           #+#    #+#             */
// /*   Updated: 2024/11/07 13:56:14 by mjuicha          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "philosophers.h"

// int     is_space(char c)
// {
//     if (c == 32 || (c >= 9 && c <= 13))
//         return (1);
//     return (0);
// }
// int left_id(t_philo *philo, int id)
// {
//     printf("left id: %d\n", id);
//     return (id);
// }

// int right_id(t_philo *philo, int id)
// {
//     printf("right id: %d\n", id);
//     if (id == philo->max_id)
//         return (0);
//     return (id + 1);
// }

// void    *philo_think(void *arg)
// {
//     t_philo *philo = (t_philo *)arg;
//     if (philo->mutex == NULL || &philo->mutex[philo->id] == NULL)
//         {
//             printf("mutex is null\n");
//             return (NULL);}
//     pthread_mutex_lock(&(philo->mutex[right_id(philo, philo->id)]));
//     printf("        %d has taken a fork\n", philo->id+1);
//     pthread_mutex_unlock(&(philo->mutex[right_id(philo, philo->id)]));
//     pthread_mutex_lock(&(philo->mutex[left_id(philo, philo->id)]));
//     printf("        %d has taken a fork\n", philo->id+1);
//     printf("philo %d is thinking\n", philo->id+1);
//     usleep(200);
//     pthread_mutex_unlock(&(philo->mutex[left_id(philo, philo->id)]));
//     return (NULL);
// }
// int     check_input(int ac, char **av)
// {
//     int i;
//     int j;

//     i = 1;
//     while (i < ac)
//     {
//         j = 0;
//         while (av[i][j])
//         {
//             while (is_space(av[i][j]))
//                 j++;
//             if (av[i][j] == '+')
//                 j++;
//             while (av[i][j] >= '0' && av[i][j] <= '9')
//                 j++;
//             if (av[i][j] == 0)
//                 break;
//             else
//                 return (0);
//         }
//         i++;
//     }
//     return (1);
// }

// void    philo_info(t_philo *philo, int ac, char **av)
// {
//     if (!av)
//         return ;
//     philo->philo_nb = ft_atoi(av[1]);
//     philo->t_die = ft_atoi(av[2]);
//     philo->t_eat = ft_atoi(av[3]);
//     philo->t_sleep = ft_atoi(av[4]);
//     if (ac == 6)
//         philo->nb_of_meals = ft_atoi(av[5]);
//     else
//         philo->nb_of_meals = -1;
// }

// int     check_philo(t_philo *philo)
// {
//     if (philo->philo_nb <= 0 || philo->t_die <= 0 || philo->t_eat <= 0 || philo->t_sleep <= 0 || philo->nb_of_meals <= 0)
//         return (1);
//     return (0);
// }

// int     is_valid_input(int ac, char **av, t_philo *philo)
// {
//     if (ac != 5 && ac != 6)
//     {
//         printf("\033[31;1mError: wrong numbers of arguments\033[0m\n");
//         return (0);
//     }
//     if (check_input(ac, av) == 0)
//     {
//         printf("\033[31;1mError: wrong arguments\033[0m\n");
//         return (0);
//     }
//     philo_info(philo, ac, av);
//     if (check_philo(philo))
//         return (printf("\033[31;1mError: wrong arguments\033[0m\n"), 0);
//     printf("\033[32;1mEverything is fine\033[0m\n");
    
//     return (1);
// }

// pthread_t create_thread()
// {
//     pthread_t thread;
//     if (!thread)
//         return (NULL);
//     return (thread);
// }

// pthread_mutex_t create_mutex()
// {
//     pthread_mutex_t mutex;
//     return (mutex);
// }


// void    init_mutex(t_philo *philo)
// {
//     // pthread_mutex_init(&philo->mutexr1, NULL);
//     // pthread_mutex_init(&philo->mutexr2, NULL);
//     // pthread_mutex_init(&philo->mutexr3, NULL);
//     // pthread_mutex_init(&philo->mutexr4, NULL);
//     // pthread_mutex_init(&philo->mutexr5, NULL);
// }

// void    ft_philo(t_philo *philo)
// {
//     if (!philo)
//         return ;
//     pthread_t *philo_thread = malloc(sizeof(pthread_t) * philo->philo_nb);
//     pthread_mutex_t *mutex = malloc(sizeof(pthread_mutex_t) * philo->philo_nb);
//     t_philo *philos = malloc(sizeof(t_philo) * philo->philo_nb);
//     if (!philo_thread || !mutex || !philos)
//         return ;
//     int nb = philo->philo_nb;
//     int i = 0;
//     while (i < nb)
//     {
//         philos[i] = *philo;
//         philos[i].id = i;
//         philos[i].mutex = mutex;
//         pthread_mutex_init(&mutex[i], NULL);
//         printf("THREAD %d\n", i);
//         i++;
//     }
//     philo->max_id = --i;
//     printf("max_id: %d\n", philo->max_id);
//     i = 0;
//     while (i < nb)
//     {
//         pthread_create(&philo_thread[i], NULL, &philo_think, &philos[i]);
//         pthread_join(philo_thread[i], NULL);
//         printf("philo %d is eating\n", i+1);
//         i += 2;
//         if (i >= nb && i % 2 == 0)
//             i = 1;
//         else if (i >= nb)
//             i = 0;
//     }
//     free(philo_thread);
//     free(mutex);
//     free(philos);
// }

// int main(int ac, char **av)
// {
//     t_philo *philo = malloc(sizeof(t_philo));
//     if (!philo)
//         return (1);
//     if (!is_valid_input(ac, av, philo))
//         return (1);
//     printf("philo_nb: %d\nt_die: %d\nt_eat: %d\nt_sleep: %d\nnb_of_meals: %d\n", philo->philo_nb, philo->t_die, philo->t_eat, philo->t_sleep, philo->nb_of_meals);
//     ft_philo(philo);
//     return (0);
// }