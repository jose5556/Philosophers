/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:50:52 by joseoliv          #+#    #+#             */
/*   Updated: 2025/02/05 20:13:49 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

bool	validate_args(int argc, char **argv)
{
	int	i;

	i = 0;
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
