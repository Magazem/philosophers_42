/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysuliman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:02:28 by ysuliman          #+#    #+#             */
/*   Updated: 2024/12/09 16:26:17 by ysuliman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	initiate_mutex(t_data *data)
{
	int	i;

	data->death = malloc(sizeof(pthread_mutex_t));
	if (!data->death)
		return (error_manager("death Malloc failed", NULL));
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philos);
	i = 0;
	if (pthread_mutex_init(data->death, NULL) == -1)
		return (error_manager("death mutex init failed", NULL));
	while (i < data->num_philos)
	{
		if (pthread_mutex_init(&data->forks[i++], NULL) == -1)
			return (error_manager("fork mutex init failed", NULL));
	}
}

void	initiate_data(int argc, char **argv, t_data *data)
{
	data->num_philos = ft_atol(argv[1]);
	data->time_to_die = ft_atol(argv[2]);
	data->time_to_eat = ft_atol(argv[3]);
	data->time_to_sleep = ft_atol(argv[4]);
	data->number_meals = -1;
	if (argc == 6)
		data->number_meals = ft_atol(argv[5]);
	data->start_time = ft_get_time();
	initiate_mutex(data);
}

void	initiate_philosophers(t_philo *philo)
{
	int	i;

	i = 1;
	while (i <= philo->data->num_philos)
	{
		philo[i].id = i;
		philo[i].dead = 0;
		philo[i].last_meal = 0;
		philo[i].eat_count = 0;
		i++;
	}
	pthread_mutex_init(philo->left_fork, NULL);
	pthread_mutex_init(philo->right_fork, NULL);
}

void	initiate_threads(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->num_philos)
		pthread_create(philo[i++].tid, NULL, &routine, philo);
	i = -1;
	philo->data->start_time = ft_get_time();
	while (++i < philo->data->num_philos)
	{
		philo[i].thread_start = philo->data->start_time;
		philo[i].last_meal = philo->data->start_time;
	}
	philo->data->over = 0;
	philo->data->ready = 1;
}

void	initiate_program(t_data *data)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo) * data->num_philos);
	philo->tid = malloc(sizeof(pthread_t) * data->num_philos);
	philo->data = data;
	initiate_philosophers(philo);
	initiate_threads(philo);
}
