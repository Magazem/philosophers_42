/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysuliman <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-16 13:47:14 by ysuliman          #+#    #+#             */
/*   Updated: 2025-01-16 13:47:14 by ysuliman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	initiate_data(int ac, char **av, t_data *data)
{
	data->num_philos = ft_atol(av[1]);
	data->time_to_eat = ft_atol(av[3]);
	data->time_to_sleep = ft_atol(av[4]);
	data->time_to_die = ft_atol(av[2]);
	data->number_meals = -1;
	if (ac == 6)
		data->number_meals = ft_atol(av[5]);
	data->start_time = ft_get_time();
	data->ready = 0;
	data->over = 0;
	pthread_mutex_init(data->lock, NULL);
}
void	init_philos(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		philo[i].id = i;
		philo[i].dead = 0;
		philo[i].data = data;
		philo[i].meal_count = 0;
		i++;
	}
	i = -1;
	while (++i < data->num_philos)
		pthread_create(&philo[i].tid, NULL, &routine, &philo[i]);
	i = -1;
	while (++i < philo->data->num_philos)
		philo[i].last_meal = philo->data->start_time;
	philo->data->ready = 1;
}

void	initiate_philo(t_data *data)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo) * data->num_philos);
	init_philos(data, philo);
	check_over(philo);
}
