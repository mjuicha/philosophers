/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 05:24:29 by mjuicha           #+#    #+#             */
/*   Updated: 2024/12/01 05:59:56 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_data	setup_data(t_philo *philo, int i)
{
	t_data	data;

	data.id = i + 1;
	data.last_meal = philo->start_time;
	data.philo = philo;
	data.still_eat = 1;
	data.ate = 0;
	return (data);
}

t_data	*get_data(t_philo *philo)
{
	int		i;

	philo->data = malloc(sizeof(t_data) * philo->philo_nb);
	if (!(philo->data))
		return (NULL);
	philo->pid = malloc(sizeof(pid_t) * philo->philo_nb);
	if (!philo->pid)
		return (NULL);
	i = 0;
	philo->is_died = 0;
	philo->start_time = get_time();
	while (i < philo->philo_nb)
	{
		philo->data[i] = setup_data(philo, i);
		i++;
	}
	return (philo->data);
}
