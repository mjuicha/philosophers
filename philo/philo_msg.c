/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 01:36:43 by mjuicha           #+#    #+#             */
/*   Updated: 2024/12/08 19:12:21 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	died_msg(t_data *data)
{
	pthread_mutex_lock(&(data->philo->print));
	printf("%ld %d died\n", time_(data->philo), data->id);
	pthread_mutex_unlock(&(data->philo->print));
	return (SUCCESS);
}

int	philo_msg(t_data *data, char *msg)
{
	pthread_mutex_lock(&(data->philo->lock));
	if (data->philo->is_died == 1)
	{
		pthread_mutex_unlock(&(data->philo->lock));
		return (FAILURE);
	}
	pthread_mutex_lock(&(data->philo->print));
	pthread_mutex_unlock(&(data->philo->lock));
	printf("%ld %d %s\n", time_(data->philo), data->id, msg);
	pthread_mutex_unlock(&(data->philo->print));
	return (SUCCESS);
}
