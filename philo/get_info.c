/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:25:19 by mjuicha           #+#    #+#             */
/*   Updated: 2024/11/24 04:53:56 by mjuicha          ###   ########.fr       */
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
    else
        philo->nb_of_meals = -1;
}

int     check_philo(t_philo *philo)
{
    if (philo->philo_nb <= 0 || philo->t_die <= 0 || philo->t_eat <= 0 || philo->t_sleep <= 0 || philo->nb_of_meals < -1 || philo->nb_of_meals == 0) 
        return (1);
    return (0);
}

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (fd < 0)
		return ;
	i = 0;
	if (!s)
		return ;
	while (s[i])
		ft_putchar_fd(s[i++], fd);
    write(fd, "\n", 1);
}


int     is_valid_input(int ac, char **av, t_philo *philo)
{
    if (ac != 5 && ac != 6)
    {
        ft_putstr_fd("Error: wrong numbers of arguments", 2);
        return (0);
    }
    if (check_input(ac, av) == 0)
    {
        ft_putstr_fd("Error: wrong arguments", 2);
        return (0);
    }
    philo_info(philo, ac, av);
    if (check_philo(philo))
        return (ft_putstr_fd("Error: wrong arguments", 2), 0);
    return (1);
}