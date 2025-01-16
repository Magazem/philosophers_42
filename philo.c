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

void	*monitor(void *philo_pointer)
{
	t_philo	*philo;

	philo = (t_philo *)philo_pointer;
	while (!philo->data->over)
	{
		if (philo->data->number_meals == philo->eat_count)
			philo->data->over = 1;
		if (ft_get_time() - philo->last_meal < philo->data->time_to_die)
			philo->data->over = 1;
	}
	return ((void *)0);
}

void	threads_end(t_philo *philo)
{
	long	num_philos;
	long	i;

	i = 0;
	num_philos = philo->data->num_philos;
	while (i < num_philos)
	{
		pthread_join(*philo[i].tid, (void *)&philo[i]);
		i++;
	}
	pthread_mutex_destroy(philo->data->forks);
	pthread_mutex_destroy(philo->data->death);
	 free(philo->data->death);
	free(philo->data->forks);
	free(philo);
}

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
