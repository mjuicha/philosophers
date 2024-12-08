/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ressources.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 00:58:42 by mjuicha           #+#    #+#             */
/*   Updated: 2024/12/08 17:35:48 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_ressources(t_philo *philo)
{
	int	i;

	i = 0;
	if (!philo)
		return ;
	pthread_mutex_destroy(&(philo->lock));
	pthread_mutex_destroy(&(philo->print));
	while (i < philo->philo_nb)
		pthread_mutex_destroy(&(philo->fork[i++]));
	free(philo->fork);
	free(philo->thread);
	free(philo);
}
