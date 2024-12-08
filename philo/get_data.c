/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 00:49:25 by mjuicha           #+#    #+#             */
/*   Updated: 2024/12/07 18:52:54 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	setup_data(t_philo *philo, int i)
{
	t_data	data;

	data.id = i + 1;
	data.last_meal = philo->start_time;
	data.right_fork = i;
	data.philo = philo;
	data.look = 1;
	data.ate = 0;
	if (i == 0)
		data.left_fork = philo->philo_nb - 1;
	else
		data.left_fork = i - 1;
	return (data);
}

t_data	*get_data(t_philo *philo)
{
	t_data	*data;
	int		i;

	data = malloc(sizeof(t_data) * philo->philo_nb);
	if (!data)
		return (NULL);
	i = 0;
	philo->data = data;
	philo->start_time = get_time();
	philo->is_died = 0;
	philo->finish = -1;
	if (philo->nb_of_meals != -1)
		philo->finish = philo->philo_nb;
	if (philo->philo_nb == 1)
		philo->nb_of_meals = -1;
	while (i < philo->philo_nb)
	{
		data[i] = setup_data(philo, i);
		i++;
	}
	return (data);
}
