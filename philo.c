/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:02:38 by mjuicha           #+#    #+#             */
/*   Updated: 2024/11/03 18:22:29 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int     is_space(char c)
{
    if (c == 32 || (c >= 9 && c <= 13))
        return (1);
    return (0);
}

int     check_input(int ac, char **av)
{
    int i;
    int j;

    i = 1;
    while (i < ac)
    {
        j = 0;
        while (av[i][j])
        {
            while (is_space(av[i][j]))
                j++;
            if (av[i][j] == '+')
                j++;
            while (av[i][j] >= '0' && av[i][j] <= '9')
                j++;
            if (av[i][j] == 0)
                break;
            else
                return (0);
        }
        i++;
    }
    return (1);
}

int     is_valid_input(int ac, char **av)
{
    if (ac != 5 && ac != 6)
    {
        printf("Error: wrong number of arguments\n");
        return (0);
    }
    if (check_input(ac, av) == 0)
    {
        printf("Error: wrong arguments\n");
        return (0);
    }
    printf("Everything is fine\n");
    return (1);
}

int main(int ac, char **av)
{
    if (!is_valid_input(ac, av))
        return (1);
    return (0);
}