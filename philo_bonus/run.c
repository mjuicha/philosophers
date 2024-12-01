/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 05:26:07 by mjuicha           #+#    #+#             */
/*   Updated: 2024/12/01 19:57:04 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*philoo(t_data *data)
{
	if (data->id % 2 == 0)
		usleep(10);
	pthread_create(&(data->philo->thread), NULL, (void *)death, data);
	pthread_detach(data->philo->thread);
	life_cycle(data);
	exit(0);
	return (NULL);
}

void	run(t_philo *philo)
{
	int		i;
	int		status;

	if (!get_data(philo))
		return ;
	i = 0;
	while (i < philo->philo_nb)
	{
		philo->pid[i] = fork();
		if (philo->pid[i] == 0)
			philoo(&(philo->data[i]));
		if (philo->pid[i] < 0)
			return ;
		i++;
	}
	while (waitpid(-1, &status, 0) > 0)
	{
		if (WIFEXITED(status) && WEXITSTATUS(status) == 1)
		{
			kill_processes(philo);
			break ;
		}
	}
}
