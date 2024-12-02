/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 01:10:22 by mjuicha           #+#    #+#             */
/*   Updated: 2024/12/02 18:04:38 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*death(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (data->philo->is_died == 0 && data->philo->stop == 0)
	{
		if ((data->last_meal + data->philo->t_die) < get_time()
			&& data->philo->philo_nb != 1)
		{
			pthread_mutex_lock(&(data->philo->_death));
			data->philo->is_died = 1;
			pthread_mutex_unlock(&(data->philo->_death));
			pthread_mutex_lock(&(data->philo->_print));
			printf("%ld %d died\n", time_(data->philo), data->id);
			pthread_mutex_unlock(&(data->philo->_print));
		}
		usleep(500);
	}
	return (NULL);
}
