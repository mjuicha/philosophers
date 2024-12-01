/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:55:46 by mjuicha           #+#    #+#             */
/*   Updated: 2024/12/01 05:44:07 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*memory;
	size_t	other;

	other = count * size;
	if (size != 0 && other / size != count)
		return (NULL);
	memory = malloc(other);
	if (memory == NULL)
		return (0);
	return (memory);
}
