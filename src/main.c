/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 18:09:40 by joseoliv          #+#    #+#             */
/*   Updated: 2025/02/05 20:24:23 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/philo.h"

int	main(int argc, char *argv[])
{
	t_philo	*philo;
	t_table	table;

	if (argc < 5 || argc > 6)
	{
		printf("%s\n", ERROR_MESSAGE_NUM_OF_ARGS);
		return (1);
	}
	else if (!validate_args(argc, argv))
		return (1);
	//init_philo(philo);
}