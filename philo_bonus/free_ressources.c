/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ressources.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 05:25:33 by mjuicha           #+#    #+#             */
/*   Updated: 2024/12/01 06:07:49 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	free_ressources(t_philo *philo)
{
	if (philo->data)
		free(philo->data);
	if (philo->pid)
		free(philo->pid);
	destroy_sem(philo);
	free(philo);
}
