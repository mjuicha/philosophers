/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 01:33:48 by mjuicha           #+#    #+#             */
/*   Updated: 2024/12/08 19:17:54 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_right_forks(t_data *data)
{
	pthread_mutex_lock(&(data->philo->fork[data->right_fork]));
	philo_msg(data, "has taken a fork");
}

void	take_left_forks(t_data *data)
{
	pthread_mutex_lock(&(data->philo->fork[data->left_fork]));
	philo_msg(data, "has taken a fork");
}

void	put_forks(t_data *data)
{
	pthread_mutex_unlock(&(data->philo->fork[data->right_fork]));
	pthread_mutex_unlock(&(data->philo->fork[data->left_fork]));
}
