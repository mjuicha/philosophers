/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 05:23:06 by mjuicha           #+#    #+#             */
/*   Updated: 2024/12/01 06:09:51 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	init_semaphores(t_philo *philo)
{
	sem_unlink("/forks");
	sem_unlink("/print");
	sem_unlink("/death");
	philo->forks = sem_open("/forks", O_CREAT, 0644, philo->philo_nb);
	philo->print = sem_open("/print", O_CREAT, 0644, 1);
	philo->death = sem_open("/death", O_CREAT, 0644, 1);
	if (philo->forks == SEM_FAILED || philo->print == SEM_FAILED
		|| philo->death == SEM_FAILED)
		return (destroy_sem(philo), FAILURE);
	return (SUCCESS);
}

void	destroy_sem(t_philo *philo)
{
	sem_close(philo->forks);
	sem_close(philo->print);
	sem_close(philo->death);
	sem_unlink("/forks");
	sem_unlink("/print");
	sem_unlink("/death");
}
