/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:18:10 by mjuicha           #+#    #+#             */
/*   Updated: 2024/12/08 20:22:03 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

# define FAILURE 0
# define SUCCESS 1

typedef struct s_data	t_data;

typedef struct s_philo
{
	pthread_t			monitor_death;
	pthread_t			*thread;
	pthread_mutex_t		*fork;
	pthread_mutex_t		lock;
	pthread_mutex_t		print;
	int					philo_nb;
	int					t_die;
	int					t_eat;
	int					is_died;
	int					t_sleep;
	int					finish;
	int					nb_of_meals;
	long				start_time;
	t_data				*data;
}						t_philo;

typedef struct s_data
{
	long		last_meal;
	int			id;
	int			right_fork;
	int			left_fork;
	int			ate;
	int			look;
	t_philo		*philo;
}				t_data;

int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
int		init_threads(t_philo *philo);
void	init_mutex(t_philo *philo);
int		is_valid_input(int ac, char **av, t_philo *philo);
t_data	*get_data(t_philo *philo);
void	run(t_philo *philo, t_data *data);
void	join(t_philo *philo);
void	*philoo(t_data *data);
void	*death(void *arg);
void	eat_(t_data *data);
void	sleep_(t_data *data);
void	think_(t_data *data);
long	time_(t_philo *philo);
long	get_time(void);
void	ft_usleep(long duration, t_data *data);
void	take_right_forks(t_data *data);
void	take_left_forks(t_data *data);
void	put_forks(t_data *data);
int		philo_msg(t_data *data, char *msg);
void	free_ressources(t_philo *philo);
int		check_death(t_data *data);
int		died_msg(t_data *data);
#endif
