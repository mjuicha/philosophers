/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 01:36:43 by mjuicha           #+#    #+#             */
/*   Updated: 2024/12/01 05:45:26 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_msg(t_data *data, char *msg)
{
	pthread_mutex_lock(&(data->philo->_print));
	if (data->philo->is_died == 0)
		printf("%ld %d %s\n", time_(data->philo), data->id, msg);
	pthread_mutex_unlock(&(data->philo->_print));
}
