/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 01:01:09 by mjuicha           #+#    #+#             */
/*   Updated: 2024/12/07 18:58:11 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	run(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	while (i < philo->philo_nb)
	{
		pthread_create(&(philo->thread[i]), NULL, (void *)&philoo, &(data[i]));
		i++;
	}
	pthread_create(&(philo->monitor_death), NULL, &death, data);
}
