/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:19:32 by mjuicha           #+#    #+#             */
/*   Updated: 2024/12/02 16:53:37 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_philo(t_philo *philo)
{
	t_data	*data;

	if (!philo)
		return ;
	if (init_threads(philo) == FAILURE)
		return (free(philo));
	init_mutex(philo);
	data = get_data(philo);
	if (!data)
		return (free_ressources(philo));
	run(philo, data);
	join(philo);
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
