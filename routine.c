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
	printf("philo %d %s\n", philo->id, action);
	pthread_mutex_unlock(philo->data->lock);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!philo->data->ready)
		continue ;
	while (1)
	{
		print_routine(philo, Alive);
	}
}
