/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cereais <cereais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:47:38 by joseoliv          #+#    #+#             */
/*   Updated: 2025/02/20 05:12:32 by cereais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FHILO_H
#define FHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>
# include <stdbool.h>

#define ERROR_MESSAGE_NUM_OF_ARGS "ERROR! Please enter: <./philo> \
<number_of_philosophers> \
<time_to_die> <time_to_eat> <time_to_sleep> \
<number_of_times_each_philosopher_must_eat>"

#define ERROR_MESSAGE_NUM_OF_PHILOS "ERROR! You need to insert \
at least one philosopher!"

#define ERROR_MESSAGE_INPUT_NUMS "ERROR! Make sure you are \
using valid integers as input!"

# define ALIVE 1
# define DEAD 2
# define EATING 3
# define SLEEPING 4
# define THINKING 5

typedef struct s_table
{
	int				num_of_philos;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	int				num_times_philo_need_to_eat;
	bool			finish;
}	t_table;

typedef struct s_philo
{
	int				id;
	int				status;
	int				nums_of_meals;
	pthread_t		*philo_thread;
	time_t			start_time;
	time_t			last_meal;
	t_table			*table;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	left_fork;
}	t_philo;

//init
t_table	init_table(char **argv, int argc);
t_philo	*init_philo(t_table table);

//utils
int		ft_atoi(const char *str);

//validation_input
bool	validate_args(int argc, char **argv);

#endif