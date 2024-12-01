/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 01:07:20 by mjuicha           #+#    #+#             */
/*   Updated: 2024/12/01 05:45:13 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*eat(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (data->still_eat == 1 && data->philo->is_died == 0)
	{
		if (data->ate == data->philo->nb_of_meals)
		{
			pthread_mutex_lock(&(data->philo->_finish_eat));
			data->still_eat = 0;
			data->philo->stop++;
			pthread_mutex_unlock(&(data->philo->_finish_eat));
			break ;
		}
	}
	return (NULL);
}
