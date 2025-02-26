/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 05:14:20 by joseoliv          #+#    #+#             */
/*   Updated: 2025/02/26 11:43:08 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	*single_rotine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	printf("%d %d has taken a fork\n", 0, philo->id);
	ft_usleep(philo->table->time_to_die);
	printf("%d %d died\n", philo->table->time_to_die, philo->id);
	return (NULL);
}

int	handle_one_philo(t_philo *philo)
{
	pthread_create(&philo->ph, NULL, &single_rotine, &philo[0]);
	pthread_join(philo->ph, NULL);
	return (1);
}
