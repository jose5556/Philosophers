/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cereais <cereais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:40:03 by joseoliv          #+#    #+#             */
/*   Updated: 2025/02/20 11:40:38 by cereais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/philo.h"

t_table	init_table(char **argv, int argc)
{
	t_table	table;

	table.num_of_philos = ft_atoi(argv[0]);
	table.time_to_die = (time_t)ft_atoi(argv[1]);
	table.time_to_eat = (time_t)ft_atoi(argv[2]);
	table.time_to_sleep = (time_t)ft_atoi(argv[3]);
	if (argc == 6)  //TODO IF ARGV[4] == 0 -> NEEDS TO EXIT
		table.num_times_philo_need_to_eat = ft_atoi(argv[4]);
	else
		table.num_times_philo_need_to_eat = -1;
	return (table);
}

t_philo	*init_philo(t_table table)
{
	t_philo *philo;
	int		i;

	i = 0;
	philo = malloc(sizeof(t_philo) * table.num_of_philos);
	if (!philo)
		return (NULL);
	while (i < table.num_of_philos)
	{
		philo[i].id = i + 1;
		philo[i].nums_of_meals = 0;
		philo[i].status = ALIVE;
		philo[i].start_time = get_time();
		philo[i].last_meal = get_time();
		pthread_mutex_init(&philo[i].left_fork, NULL);
		if (i == table.num_of_philos - 1)
			philo[i].right_fork = &philo[0].left_fork;
		else
			philo[i].right_fork = &philo[i + 1].left_fork;
		philo[i].table = &table;
		i++;
	}
}

void	init_threads(t_philo *philo)
{
	int	i;

	i = 0;
	if (philo->table->num_of_philos == 1)
		return (handle_one_philo(philo));
	while (i < philo->table->num_of_philos)
	{
		if (pthread_create(&philo[i].philo_thread, NULL, &simulation, &philo[i]) != 0)
		{
			printf("pthread_create error!\n");
			return ;
		}
		i++;
	}
}
