/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 05:31:02 by mjuicha           #+#    #+#             */
/*   Updated: 2024/12/01 18:55:27 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	eat_(t_data *data)
{
	sem_wait(data->philo->print);
	data->last_meal = get_time();
	printf("%ld %d is eating\n", get_time() - data->philo->start_time, data->id);
	data->ate++;
	sem_post(data->philo->print);
	if (data->ate == data->philo->nb_of_meals)
		data->still_eat = 0;
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
