/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ressources.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 00:58:42 by mjuicha           #+#    #+#             */
/*   Updated: 2024/12/01 05:44:35 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_ressources(t_philo *philo)
{
	int	i;

	i = 0;
	if (!philo)
		return ;
	pthread_mutex_destroy(&(philo->_meal));
	pthread_mutex_destroy(&(philo->_print));
	pthread_mutex_destroy(&(philo->_death));
	pthread_mutex_destroy(&(philo->_finish_eat));
	while (i < philo->philo_nb)
		pthread_mutex_destroy(&(philo->forks[i++]));
	free(philo->monitor_death);
	if (philo->nb_of_meals != -1)
		free(philo->monitor_meal);
	free(philo->forks);
	free(philo->thread);
	free(philo);
}
