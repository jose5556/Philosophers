/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_th_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 06:04:32 by joseoliv          #+#    #+#             */
/*   Updated: 2025/02/25 06:25:53 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/philo.h"

void	last_th_handler(t_philo *philos)
{
	int	n;

	n = 0;
	while (n < philos->table->numbers_of_philosophers)
	{
		if (pthread_join(philos[n].ph, NULL) != 0)
			return ;
		n++;
	}
	n = 0;
	while (n < philos->table->numbers_of_philosophers)
	{
		pthread_mutex_destroy(&philos[n].left_fork);
		pthread_mutex_destroy(&philos[n].philo);
		n++;
	}
	pthread_mutex_destroy(&philos->table->info);
	free(philos);
}
