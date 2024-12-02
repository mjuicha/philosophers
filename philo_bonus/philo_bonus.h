/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 04:10:20 by mjuicha           #+#    #+#             */
/*   Updated: 2024/12/02 19:22:41 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <fcntl.h>

# define SUCCESS 1
# define FAILURE 0

typedef struct s_philo	t_philo;
typedef struct s_data
{
	int					id;
	long				last_meal;
	t_philo				*philo;
	int					still_eat;
	int					ate;
}						t_data;

typedef struct s_philo
{
	int					philo_nb;
	int					t_die;
	int					t_eat;
	int					t_sleep;
	int					nb_of_meals;
	long				start_time;
	int					is_died;
	pid_t				*pid;
	t_data				*data;
	pthread_t			thread;
	sem_t				*forks;
	sem_t				*print;
	sem_t				*death;
}						t_philo;

int		ft_atoi(const char *str);
int		is_valid_input(int ac, char **av, t_philo *philo);
int		init_semaphores(t_philo *philo);
t_data	*get_data(t_philo *philo);
void	free_ressources(t_philo *philo);
int		run(t_philo *philo);
void	destroy_sem(t_philo *philo);
void	life_cycle(t_data *data);
void	eat_(t_data *data);
void	sleep_(t_data *data);
void	think_(t_data *data);
void	*philoo(t_data *data);
void	philo_msg(t_data *data, char *msg);
void	ft_usleep(long duration);
long	time_(t_philo *philo);
long	get_time(void);
void	kill_processes(t_philo *philo);
void	*death(t_data *data);
#endif
