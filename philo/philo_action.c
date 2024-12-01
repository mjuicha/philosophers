/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 01:13:51 by mjuicha           #+#    #+#             */
/*   Updated: 2024/12/01 05:44:58 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	one_philo(t_philo *philo)
{
	if (philo->philo_nb == 1)
	{
		ft_usleep(philo->t_die);
		pthread_mutex_lock(&(philo->_print));
		printf("%ld %d died\n", time_(philo), 1);
		pthread_mutex_unlock(&(philo->_print));
		return (SUCCESS);
	}
	return (FAILURE);
}

void	*philoo(t_data *data)
{
	if (data->id % 2 == 0)
		ft_usleep(10);
	while (data->philo->is_died == 0 && data->still_eat == 1)
	{
		take_right_forks(data);
		if (one_philo(data->philo) == SUCCESS)
			break ;
		take_left_forks(data);
		eat_(data);
		put_forks(data);
		sleep_(data);
		think_(data);
		usleep(100);
	}
	return (NULL);
}
