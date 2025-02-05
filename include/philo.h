/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:47:38 by joseoliv          #+#    #+#             */
/*   Updated: 2025/02/05 20:28:47 by joseoliv         ###   ########.fr       */
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

#define ERROR_MESSAGE_INPUT_NUMS "ERROR! certificate that you are \
using valid integers as input!"

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
	int				numsof_meals;
	pthread_t		philo_thread;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	left_fork;
	time_t			start_time;
	time_t			last_meal;
	t_table			*table;
}	t_philo;

//init
//void	init();

//utils
int		ft_atoi(const char *str);

//validation_input
bool	validate_args(int argc, char **argv);

#endif