/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_funcs_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 06:02:43 by joseoliv          #+#    #+#             */
/*   Updated: 2025/02/26 11:42:34 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	set_info_int(pthread_mutex_t *mutex, int *value, int info)
{
	pthread_mutex_lock(mutex);
	*value = info;
	pthread_mutex_unlock(mutex);
}

void	set_info_long(pthread_mutex_t *mutex, long long *value, long long info)
{
	pthread_mutex_lock(mutex);
	*value = info;
	pthread_mutex_unlock(mutex);
}

void	set_bool(pthread_mutex_t *mutex, bool *value, bool info)
{
	pthread_mutex_lock(mutex);
	*value = info;
	pthread_mutex_unlock(mutex);
}

void	lock_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(&philo->left_fork);
	}
	else
	{
		pthread_mutex_lock(&philo->left_fork);
		pthread_mutex_lock(philo->right_fork);
	}
}

void	unlock_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}
