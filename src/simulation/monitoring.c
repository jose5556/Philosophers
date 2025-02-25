/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 06:00:53 by joseoliv          #+#    #+#             */
/*   Updated: 2025/02/25 06:30:27 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/philo.h"

int	monitoring(t_philo *philos)
{
	int			n;
	int			count;
	long long	diff_time;

	n = 0;
	count = 0;
	while (n < philos->table->numbers_of_philosophers)
	{
		diff_time = get_time() - get_info_long(&philos->table->info, \
			&philos[n].last_meal);
		if (philos->table->time_to_die <= diff_time && \
		get_info_int(&philos[n].philo, &philos[n].status) != EATING)
			return (dead_print(&philos[n]));
		if (philos->table->number_of_times_to_eat == \
			get_info_long(&philos[n].philo, &philos[n].number_of_meal))
			count++;
		n++;
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
