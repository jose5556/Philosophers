/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_th_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 06:04:32 by joseoliv          #+#    #+#             */
/*   Updated: 2025/02/26 11:43:14 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	last_th_handler(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->table->numbers_of_philosophers)
	{
		if (pthread_join(philos[i].ph, NULL) != 0)
			return ;
		i++;
	}
	i = 0;
	while (i < philos->table->numbers_of_philosophers)
	{
		pthread_mutex_destroy(&philos[i].left_fork);
		pthread_mutex_destroy(&philos[i].philo);
		i++;
	}
	pthread_mutex_destroy(&philos->table->info);
	free(philos);
}
