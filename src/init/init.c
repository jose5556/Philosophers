/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:40:03 by joseoliv          #+#    #+#             */
/*   Updated: 2025/02/26 11:42:54 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

t_table	init_table(int argc, char **argv)
{
	t_table	table;

	table.numbers_of_philosophers = ft_atoi(argv[1]);
	table.time_to_die = ft_atoi(argv[2]);
	table.time_to_eat = ft_atoi(argv[3]);
	table.time_to_sleep = ft_atoi(argv[4]);
	table.finish = false;
	table.done = false;
	pthread_mutex_init(&table.info, NULL);
	if (argc == 6)
		table.number_of_times_to_eat = ft_atoi(argv[5]);
	else
		table.number_of_times_to_eat = -1;
	return (table);
}

t_philo	*init_philos(t_table *table)
{
	t_philo	*philos;
	int		i;

	i = 0;
	philos = (t_philo *)malloc(sizeof(t_philo)
			* table->numbers_of_philosophers);
	if (!philos)
		return (NULL);
	while (i < table->numbers_of_philosophers)
	{
		philos[i].id = i + 1;
		philos[i].table = table;
		philos[i].number_of_meal = 0;
		philos[i].status = ALIVE;
		philos[i].last_meal = get_time();
		philos[i].start_time = get_time();
		pthread_mutex_init(&philos[i].left_fork, NULL);
		pthread_mutex_init(&philos[i].philo, NULL);
		if (i == table->numbers_of_philosophers - 1)
			philos[i].right_fork = &philos[0].left_fork;
		else
			philos[i].right_fork = &philos[i + 1].left_fork;
		i++;
	}
	return (philos);
}

int	init_threads(t_philo *philos)
{
	int	i;

	i = 0;
	if (philos->table->numbers_of_philosophers == 1)
		return (handle_one_philo(philos));
	while (i < philos->table->numbers_of_philosophers)
	{
		if (pthread_create(&philos[i].ph, NULL, &rotine, &philos[i]) != 0)
			return (2);
		i++;
	}
	set_bool(&philos->table->info, &philos->table->done, true);
	while (get_bool(&philos->table->info, &philos->table->finish) == false)
		monitoring(philos);
	return (0);
}
