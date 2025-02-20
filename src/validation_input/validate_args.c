/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cereais <cereais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:50:52 by joseoliv          #+#    #+#             */
/*   Updated: 2025/02/17 04:23:49 by cereais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

bool	validate_args(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argv[1][0] == '0' && !(argv[1][1]))
	{
		printf("%s\n", ERROR_MESSAGE_NUM_OF_PHILOS);
		return (false);
	}
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == -1)
		{
			printf("%s\n", ERROR_MESSAGE_INPUT_NUMS);
			return (false);
		}
		i++;
	}
	return (true);
}
