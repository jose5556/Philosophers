/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:28:43 by joseoliv          #+#    #+#             */
/*   Updated: 2025/02/05 19:14:05 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>

time_t	get_time();

int	mails = 0;
pthread_mutex_t mutex;

static void	*random_func(void *args)
{
	int	i;
	

	i = 0;
	while (i < 50000)
	{
		pthread_mutex_lock(&mutex);
		mails++;
		i++;
		pthread_mutex_unlock(&mutex);
	}
	printf("thread num, %d finished his operation!\n", *(int*)args);
	return (NULL);
}

int	main(int argc, char *argv[])
{
	pthread_t	p1, p2, p3;
	int			i, j, k;
	time_t		time;

	time = get_time();
	i = 1;
	j = 2;
	k = 3;
	pthread_mutex_init(&mutex, NULL);
	/* if (argc != 5 || argc != 6)
	{
		printf("argument/s is/are not acceptable");
		return (1);
	} */
	if (pthread_create(&p1, NULL, &random_func, &i) != 0)
		printf("nop on create\n");
	if (pthread_create(&p2, NULL, &random_func, &j) != 0)
		printf("nop on create\n");
	if (pthread_create(&p3, NULL, &random_func, &k) != 0)
		printf("nop on create\n");
	pthread_join(p1, NULL);
	pthread_join(p2, NULL);
	pthread_join(p3, NULL);

	pthread_mutex_destroy(&mutex);
	printf("All %d mails were sent within only %ld milliseconds\n",
		mails, get_time() - time);
	return (0);
}

time_t	get_time()
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
