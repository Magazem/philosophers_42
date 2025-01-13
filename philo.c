/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysuliman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:31:13 by ysuliman          #+#    #+#             */
/*   Updated: 2024/12/05 17:02:32 by ysuliman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (check_args(ac, av))
	{
		initiate_data(ac, av, &data);
		initiate_program(&data);
	}
	return (0);
}
void	monitor(t_philo *philo)
{
	
}
void	threads_end(t_philo *philo)
{
	long num_philos;
	long i;

	i = 0;
	num_philos = philo->data->num_philos;
	while (i < num_philos)
	{
		pthread_join(philo[i].tid, (void *)&philo[i]);
		i++;
	}
	pthread_mutexattr_destroy(philo->data->forks);
	pthread_mutexattr_destroy(philo->data->death);
	free(philo->data->death);
	free(philo->data->forks);
	free(philo);
}