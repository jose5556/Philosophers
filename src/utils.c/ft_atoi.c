/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:06:40 by joseoliv          #+#    #+#             */
/*   Updated: 2025/02/05 20:17:15 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			return (-1);
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num);
}
