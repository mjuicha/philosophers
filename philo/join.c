/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 01:03:42 by mjuicha           #+#    #+#             */
/*   Updated: 2024/12/07 18:38:11 by mjuicha          ###   ########.fr       */
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
		i++;
	}
	pthread_join(philo->monitor_death, NULL);
	free(philo->data);
	free_ressources(philo);
}
