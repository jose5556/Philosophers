/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:40:03 by joseoliv          #+#    #+#             */
/*   Updated: 2025/02/25 06:33:39 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/philo.h"

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
	{
		table.number_of_times_to_eat = ft_atoi(argv[5]);
		if (table.number_of_times_to_eat == 0)
			exit(EXIT_SUCCESS);
	}
	else
		table.number_of_times_to_eat = -1;
	return (table);
}

t_philo	*init_philos(t_table *table)
{
	t_philo	*philos;
	int		n;

	n = 0;
	philos = (t_philo *)malloc(sizeof(t_philo) * table->numbers_of_philosophers);
	if (!philos)
		return (NULL);
	while (n < table->numbers_of_philosophers)
	{
		philos[n].id = n + 1;
		philos[n].table = table;
		philos[n].number_of_meal = 0;
		philos[n].status = ALIVE;
		philos[n].last_meal = get_time();
		philos[n].start_time = get_time();
		pthread_mutex_init(&philos[n].left_fork, NULL);
		pthread_mutex_init(&philos[n].philo, NULL);
		if (n == table->numbers_of_philosophers - 1)
			philos[n].right_fork = &philos[0].left_fork;
		else
			philos[n].right_fork = &philos[n + 1].left_fork;
		n++;
	}
	return (philos);
}

int	init_threads(t_philo *philos)
{
	int	n;

	n = 0;
	if (philos->table->numbers_of_philosophers == 1)
		return (handle_one_philo(philos));
	while (n < philos->table->numbers_of_philosophers)
	{
		if (pthread_create(&philos[n].ph, NULL, &rotine, &philos[n]) != 0)
			return (2);
		n++;
	}
	set_bool(&philos->table->info, &philos->table->done, true);
	while (get_bool(&philos->table->info, &philos->table->finish) == false)
		monitoring(philos);
	return (0);
}
