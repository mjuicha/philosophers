/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 05:31:56 by mjuicha           #+#    #+#             */
/*   Updated: 2024/12/01 06:43:06 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philo_msg(t_data *data, char *msg)
{
	sem_wait(data->philo->print);
	printf("%ld %d %s\n", time_(data->philo), data->id, msg);
	sem_post(data->philo->print);
}
