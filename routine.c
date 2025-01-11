/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysuliman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:12:27 by ysuliman          #+#    #+#             */
/*   Updated: 2024/12/16 10:45:12 by ysuliman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_routine(t_philo *philo, char *action)
{
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_routine(philo, L_FORK);
	pthread_mutex_lock(philo->right_fork);
	print_routine(philo, R_FORK);
	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	philo_sleep_think(t_philo *philo)
{
}

void	routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	while (!p->data->ready)
		continue ;
	if (p->id & 1)
		ft_usleep(p->data->time_to_eat * 0.9 + 1);
	while (!p->data->over)
	{
		philo_eat(p);
		philo_sleep_think(p);
	}
}
