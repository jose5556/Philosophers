/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 18:09:40 by joseoliv          #+#    #+#             */
/*   Updated: 2025/02/26 11:42:23 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char *argv[])
{
	t_philo	*philos;
	t_table	table;

	if (argc < 5 || argc > 6)
	{
		printf("%s\n", ERROR_MESSAGE_NUM_OF_ARGS);
		return (1);
	}
	else if (!validate_args(argc, argv))
		return (1);
	table = init_table(argc, argv);
	philos = init_philos(&table);
	init_threads(philos);
	last_th_handler(philos);
}
