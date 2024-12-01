/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 00:30:33 by mjuicha           #+#    #+#             */
/*   Updated: 2024/12/01 06:11:29 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_threads(t_philo *philo)
{
	philo->forks = ft_calloc(philo->philo_nb, sizeof(pthread_mutex_t));
	if (!philo->forks)
		return (FAILURE);
	philo->thread = ft_calloc(philo->philo_nb, sizeof(pthread_t));
	if (!philo->thread)
		return (free(philo->forks), FAILURE);
	philo->monitor_death = ft_calloc(philo->philo_nb, sizeof(pthread_t));
	if (!philo->monitor_death)
		return (free(philo->forks), free(philo->thread), FAILURE);
	if (philo->nb_of_meals != -1)
	{
		philo->monitor_meal = ft_calloc(philo->philo_nb, sizeof(pthread_t));
		if (!philo->monitor_meal)
		{
			free(philo->forks);
			free(philo->thread);
			free(philo->monitor_death);
			return (FAILURE);
		}
	}
	return (SUCCESS);
}

void	init_mutex(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->philo_nb)
	{
		pthread_mutex_init(&(philo->forks[i]), NULL);
		i++;
	}
	pthread_mutex_init(&(philo->_meal), NULL);
	pthread_mutex_init(&(philo->_print), NULL);
	pthread_mutex_init(&(philo->_death), NULL);
	pthread_mutex_init(&(philo->_finish_eat), NULL);
}
