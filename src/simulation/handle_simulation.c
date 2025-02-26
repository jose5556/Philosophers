/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_simulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 05:38:52 by joseoliv          #+#    #+#             */
/*   Updated: 2025/02/26 11:43:12 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	*rotine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (get_bool(&philo->table->info, &philo->table->done) != true)
		;
	set_info_long(&philo->philo, \
			&philo->start_time, get_time());
	set_info_long(&philo->table->info, \
			&philo->last_meal, get_time());
	while (get_bool(&philo->table->info, &philo->table->finish) == false)
	{
		thinking(philo);
		eating(philo);
		sleeping(philo);
	}
	return (NULL);
}

void	eating(t_philo *philo)
{
	long long	time;

	lock_forks(philo);
	if (get_bool(&philo->table->info, &philo->table->finish) == true || \
	get_info_int(&philo->philo, &philo->status) == DEAD)
		return (unlock_forks(philo));
	time = get_time() - get_info_long(&philo->philo, &philo->start_time);
	printf("%lld %d has taken a fork\n", time, philo->id);
	printf("%lld %d has taken a fork\n", time, philo->id);
	printf("%lld %d is eating\n", time, philo->id);
	set_info_int(&philo->philo, &philo->status, EATING);
	set_info_long(&philo->table->info, &philo->last_meal, get_time());
	ft_usleep(philo->table->time_to_eat);
	if (get_info_long(&philo->table->info, &philo->number_of_meal) \
	!= philo->table->number_of_times_to_eat)
		set_info_long(&philo->philo, &philo->number_of_meal, \
			(get_info_long(&philo->table->info, &philo->number_of_meal) + 1));
	unlock_forks(philo);
}

void	sleeping(t_philo *philo)
{
	long long	time;

	if (get_bool(&philo->table->info, &philo->table->finish) == true || \
		get_info_int(&philo->table->info, &philo->status) != EATING)
		return ;
	time = get_time() - get_info_long(&philo->philo, &philo->start_time);
	printf("%lld %d is sleeping\n", time, philo->id);
	set_info_int(&philo->philo, &philo->status, SLEEPING);
	ft_usleep(philo->table->time_to_sleep);
}

void	thinking(t_philo *philo)
{
	long long	time;

	if (get_bool(&philo->table->info, &philo->table->finish) == true || \
		get_info_int(&philo->table->info, &philo->status) == THINKING)
		return ;
	time = get_time() - get_info_long(&philo->philo, &philo->start_time);
	printf("%lld %d is thinking\n", time, philo->id);
	set_info_int(&philo->philo, &philo->status, THINKING);
	ft_usleep(1);
}
