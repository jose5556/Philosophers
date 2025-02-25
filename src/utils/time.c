/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 05:53:14 by cereais           #+#    #+#             */
/*   Updated: 2025/02/25 06:08:10 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

long long	get_time(void)
{
	long long			current_time;
	struct timeval		st;

	gettimeofday(&st, NULL);
	current_time = (long long)st.tv_sec * 1000 + (long long)st.tv_usec / 1000;
	return (current_time);
}

int	ft_usleep(long long milliseconds)
{
	long long	start;

	start = get_time();
	while ((get_time() - start) < milliseconds)
		usleep(500);
	return (0);
}
