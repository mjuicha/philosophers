/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 05:45:10 by mjuicha           #+#    #+#             */
/*   Updated: 2024/12/01 05:57:31 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	is_space(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	check_input(int ac, char **av)
{
	int	i;
	int	j;

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
				break ;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	collect_info(t_philo *philo, int ac, char **av)
{
	if (!av)
		return (1);
	philo->philo_nb = ft_atoi(av[1]);
	philo->t_die = ft_atoi(av[2]);
	philo->t_eat = ft_atoi(av[3]);
	philo->t_sleep = ft_atoi(av[4]);
	if (ac == 6)
		philo->nb_of_meals = ft_atoi(av[5]);
	if (philo->philo_nb <= 0 || philo->t_die <= 0 || philo->t_eat <= 0
		|| philo->t_sleep <= 0 || (ac == 6 && philo->nb_of_meals <= 0))
		return (1);
	if (ac == 5)
		philo->nb_of_meals = -1;
	return (0);
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
		write(fd, &s[i++], 1);
	write(fd, "\n", 1);
}

int	is_valid_input(int ac, char **av, t_philo *philo)
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
	if (collect_info(philo, ac, av))
		return (ft_putstr_fd("Error: wrong arguments", 2), 0);
	return (1);
}
