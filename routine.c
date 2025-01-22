/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysuliman <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-16 16:05:51 by ysuliman          #+#    #+#             */
/*   Updated: 2025-01-16 16:05:51 by ysuliman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_routine(t_philo *philo, char *action)
{
	pthread_mutex_lock(philo->data->lock);
	printf("%ld %d %s\n", ft_get_time() - philo->data->start_time, philo->id,
		action);
	pthread_mutex_unlock(philo->data->lock);
}

void	sleep_think(t_philo *philo)
{
	print_routine(philo, SLEEP);
	ft_usleep(philo->data->time_to_sleep);
	print_routine(philo, THINK);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_routine(philo, FORK);
	pthread_mutex_lock(philo->right_fork);
	print_routine(philo, FORK);
	philo->meal_count++;
	philo->last_meal = ft_get_time();
	print_routine(philo, EAT);
	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!philo->data->ready)
		continue ;
	if (philo->id & 1)
		ft_usleep(philo->data->time_to_eat * 0.9 + 1);
	while (1)
	{
		eat(philo);
		sleep_think(philo);
	}
}
