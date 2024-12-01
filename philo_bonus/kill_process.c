/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_processs_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 05:35:16 by mjuicha           #+#    #+#             */
/*   Updated: 2024/12/01 06:06:09 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	kill_processes(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->philo_nb)
	{
		kill(philo->pid[i], SIGTERM);
		i++;
	}
}
