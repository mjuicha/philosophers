/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 00:30:33 by mjuicha           #+#    #+#             */
/*   Updated: 2024/12/08 17:34:04 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_threads(t_philo *philo)
{
	philo->fork = ft_calloc(philo->philo_nb, sizeof(pthread_mutex_t));
	if (!philo->fork)
		return (FAILURE);
	philo->thread = ft_calloc(philo->philo_nb, sizeof(pthread_t));
	if (!philo->thread)
		return (free(philo->fork), FAILURE);
	return (SUCCESS);
}

void	init_mutex(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->philo_nb)
	{
		pthread_mutex_init(&(philo->fork[i]), NULL);
		i++;
	}
	pthread_mutex_init(&(philo->lock), NULL);
	pthread_mutex_init(&(philo->print), NULL);
}
