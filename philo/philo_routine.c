/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 01:28:20 by mjuicha           #+#    #+#             */
/*   Updated: 2024/12/01 05:45:58 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat_(t_data *data)
{
	philo_msg(data, "is eating");
	pthread_mutex_lock(&(data->philo->_meal));
	data->last_meal = get_time();
	data->ate++;
	pthread_mutex_unlock(&(data->philo->_meal));
	ft_usleep(data->philo->t_eat);
}

void	sleep_(t_data *data)
{
	philo_msg(data, "is sleeping");
	ft_usleep(data->philo->t_sleep);
}

void	think_(t_data *data)
{
	philo_msg(data, "is thinking");
}
