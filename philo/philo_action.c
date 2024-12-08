/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 01:13:51 by mjuicha           #+#    #+#             */
/*   Updated: 2024/12/08 18:30:11 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	one_philo(t_philo *philo)
{
	ft_usleep(philo->t_die, philo->data);
	died_msg(philo->data);
	return (SUCCESS);
}

int	check_death(t_data *data)
{
	pthread_mutex_lock(&(data->philo->lock));
	if (data->philo->is_died == 1)
	{
		pthread_mutex_unlock(&(data->philo->lock));
		return (1);
	}
	pthread_mutex_unlock(&(data->philo->lock));
	return (0);
}

void	get_last_meal(t_data *data)
{
	pthread_mutex_lock(&(data->philo->lock));
	data->last_meal = get_time();
	pthread_mutex_unlock(&(data->philo->lock));
}

int	check_meal(t_data *data)
{
	pthread_mutex_lock(&(data->philo->lock));
	if (data->philo->nb_of_meals != -1)
	{
		if (data->ate == data->philo->nb_of_meals)
		{
			pthread_mutex_unlock(&(data->philo->lock));
			return (1);
		}
	}
	pthread_mutex_unlock(&(data->philo->lock));
	return (0);
}

void	*philoo(t_data *data)
{
	if (data->id % 2 == 0)
		ft_usleep(10, data);
	get_last_meal(data);
	if (data->philo->philo_nb == 1)
	{
		take_right_forks(data);
		one_philo(data->philo);
		return (NULL);
	}
	while (1)
	{
		if (check_death(data) || check_meal(data))
			break ;
		take_right_forks(data);
		take_left_forks(data);
		eat_(data);
		put_forks(data);
		sleep_(data);
		think_(data);
	}
	return (NULL);
}
