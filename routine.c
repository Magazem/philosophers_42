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

void	philo_eat(t_philo *philo)
{
}

void	philo_sleep_think(t_philo *philo)
{
}

void	print_routine(t_philo *philo)
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
	while (p->dead)
	{
	}
}
