/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:47:04 by joseoliv          #+#    #+#             */
/*   Updated: 2025/02/26 11:49:54 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>
# include <stdbool.h>

# define ERROR_MESSAGE_NUM_OF_ARGS "ERROR! Please enter: <./philo> \
<number_of_philosophers> \
<time_to_die> <time_to_eat> <time_to_sleep> \
<number_of_times_each_philosopher_must_eat>"

# define ERROR_MESSAGE_NUM_OF_PHILOS "ERROR! You need to insert \
at least one philosopher!"

# define ERROR_MESSAGE_INPUT_NUMS "ERROR! Make sure you are \
using valid integers as input!"

# define ALIVE 1
# define DEAD 2
# define EATING 3
# define SLEEPING 4
# define THINKING 5

typedef struct s_table
{
	int					numbers_of_philosophers;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					number_of_times_to_eat;
	bool				finish;
	bool				done;
	pthread_mutex_t		info;
}	t_table;

typedef struct s_philo
{
	int					id;
	int					status;
	long long			number_of_meal;
	long long			last_meal;
	long long			start_time;
	pthread_t			ph;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		left_fork;
	pthread_mutex_t		philo;
	t_table				*table;
}	t_philo;

//init
t_table		init_table(int argc, char **argv);
t_philo		*init_philos(t_table *table);
int			init_threads(t_philo *philos);

//utils
int			ft_atoi(const char *str);
long long	get_time(void);
int			ft_usleep(long long milliseconds);

//validation_input
bool		validate_args(int argc, char **argv);

//mutex
void		set_info_int(pthread_mutex_t *mutex, int *value, int info);
void		set_info_long(pthread_mutex_t *mutex, long long *value,
				long long info);
void		set_bool(pthread_mutex_t *mutex, bool *value, bool info);
void		lock_forks(t_philo *philo);
void		unlock_forks(t_philo *philo);
int			get_info_int(pthread_mutex_t *mutex, int *info);
long long	get_info_long(pthread_mutex_t *mutex, long long *info);
bool		get_bool(pthread_mutex_t *mutex, bool *info);

//simulation
void		*rotine(void *arg);
void		eating(t_philo *philo);
void		sleeping(t_philo *philo);
void		thinking(t_philo *philo);
int			monitoring(t_philo *philos);
int			dead_print(t_philo *philo);
int			handle_one_philo(t_philo *philo);
void		*single_rotine(void *data);

//threads_handler
void		last_th_handler(t_philo *philos);

#endif