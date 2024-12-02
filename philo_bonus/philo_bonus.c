/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 05:44:28 by mjuicha           #+#    #+#             */
/*   Updated: 2024/12/02 14:14:44 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_philo(t_philo *philo)
{
	int	i;

	if (!philo)
		return ;
	if (init_semaphores(philo) == FAILURE)
		return (free(philo));
	if (run(philo) == FAILURE)
		return (free_ressources(philo));
	i = 0;
	while (i < philo->philo_nb)
		waitpid(philo->pid[i++], NULL, 0);
	free_ressources(philo);
}

int	main(int ac, char **av)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (1);
	if (!is_valid_input(ac, av, philo))
		return (free(philo), 1);
	ft_philo(philo);
	return (0);
}
