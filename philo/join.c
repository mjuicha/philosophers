/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 01:03:42 by mjuicha           #+#    #+#             */
/*   Updated: 2024/12/02 18:16:27 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	join(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->philo_nb)
	{
		pthread_join(philo->thread[i], NULL);
		pthread_join(philo->monitor_death[i], NULL);
		if (philo->nb_of_meals != -1)
			pthread_join(philo->monitor_meal[i], NULL);
		i++;
	}
	free(philo->data);
	free_ressources(philo);
}
