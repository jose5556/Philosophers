/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_funcs_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 06:03:09 by joseoliv          #+#    #+#             */
/*   Updated: 2025/02/25 06:03:26 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/philo.h"

int	get_info_int(pthread_mutex_t *mutex, int *info)
{
	int	value;

	pthread_mutex_lock(mutex);
	value = *info;
	pthread_mutex_unlock(mutex);
	return (value);
}

long long	get_info_long(pthread_mutex_t *mutex, long long *info)
{
	long long	value;

	pthread_mutex_lock(mutex);
	value = *info;
	pthread_mutex_unlock(mutex);
	return (value);
}

bool	get_bool(pthread_mutex_t *mutex, bool *info)
{
	bool	value;

	pthread_mutex_lock(mutex);
	value = *info;
	pthread_mutex_unlock(mutex);
	return (value);
}
