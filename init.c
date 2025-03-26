/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysuliman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:47:14 by ysuliman          #+#    #+#             */
/*   Updated: 2025/03/26 08:13:34 by ysuliman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	over(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->data->num_philos)
		pthread_join(philo[i].tid, NULL);
	pthread_mutex_destroy(philo->data->forks);
	pthread_mutex_destroy(philo->data->lock);
	pthread_mutex_destroy(philo->data->meals);
	free(philo->data->lock);
	free(philo->data->meals);
	free(philo->data->forks);
	free(philo);
}

void	initiate_data(int ac, char **av, t_data *data)
{
	int	i;

	data->num_philos = ft_atol(av[1]);
	data->time_to_eat = ft_atol(av[3]);
	data->time_to_sleep = ft_atol(av[4]);
	data->time_to_die = ft_atol(av[2]);
	data->full = 0;
	data->number_meals = -1;
	if (ac == 6)
		data->number_meals = ft_atol(av[5]);
	data->start_time = ft_get_time();
	data->ready = 0;
	data->over = 0;
	data->lock = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(data->lock, NULL);
	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philos);
	data->meals = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(data->meals, NULL);
	while (i < data->num_philos)
		pthread_mutex_init(&data->forks[i++], NULL);
}

void	init_philos(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		philo[i].id = i + 1;
		philo[i].dead = 0;
		philo[i].data = data;
		philo[i].meal_count = 0;
		philo[i].left_fork = &data->forks[i];
		philo[i].right_fork = 0;
		i++;
	}
	i = -1;
	while (++i < data->num_philos)
	{
		philo[i].right_fork = philo[(i + 1) % data->num_philos].left_fork;
		pthread_create(&philo[i].tid, NULL, &routine, &philo[i]);
	}
	i = -1;
	while (++i < philo->data->num_philos)
		philo[i].last_meal = ft_get_time();
	philo->data->ready = 1;
}

void	initiate_philo(t_data *data)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo) * data->num_philos);
	init_philos(data, philo);
	check_over(philo);
	if (philo->data->num_philos > 1)
		over(philo);
}
