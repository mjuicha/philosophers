/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 01:10:22 by mjuicha           #+#    #+#             */
/*   Updated: 2024/12/08 20:05:39 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_died(t_data *data, int i)
{
	pthread_mutex_lock(&(data[i].philo->lock));
	if ((get_time() - data[i].last_meal) >= data[i].philo->t_die
		&& data[i].look)
	{
		data[i].philo->is_died = 1;
		pthread_mutex_unlock(&(data[i].philo->lock));
		died_msg(&data[i]);
		return (SUCCESS);
	}
	if (data[i].philo->finish == 0)
	{
		pthread_mutex_unlock(&(data[i].philo->lock));
		return (SUCCESS);
	}
	pthread_mutex_unlock(&(data[i].philo->lock));
	return (FAILURE);
}

void	*death(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	while (1)
	{
		i = 0;
		if (data[i].philo->philo_nb == 1)
			break ;
		while (i < data->philo->philo_nb)
		{
			if (check_died(data, i) == SUCCESS)
				return (NULL);
			i++;
		}
	}
	return (NULL);
}
