/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 06:00:53 by joseoliv          #+#    #+#             */
/*   Updated: 2025/02/26 11:43:11 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	monitoring(t_philo *philos)
{
	int			i;
	int			count;
	long long	diff_time;

	i = 0;
	count = 0;
	while (i < philos->table->numbers_of_philosophers)
	{
		diff_time = get_time() - get_info_long(&philos->table->info, \
			&philos[i].last_meal);
		if (philos->table->time_to_die <= diff_time && \
		get_info_int(&philos[i].philo, &philos[i].status) != EATING)
			return (dead_print(&philos[i]));
		if (philos->table->number_of_times_to_eat == \
			get_info_long(&philos[i].philo, &philos[i].number_of_meal))
			count++;
		i++;
	}
	if (philos->table->numbers_of_philosophers == count)
		set_bool(&philos->table->info, &philos->table->finish, true);
	return (1);
}

int	dead_print(t_philo *philo)
{
	long long	current_time;

	current_time = get_time();
	printf("%lld %d died\n", current_time - \
	get_info_long(&philo->table->info, &philo->start_time), philo->id);
	set_bool(&philo->table->info, &philo->table->finish, true);
	set_info_int(&philo->philo, &philo->status, DEAD);
	return (1);
}
