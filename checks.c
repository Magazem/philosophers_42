/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysuliman <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-16 19:04:28 by ysuliman          #+#    #+#             */
/*   Updated: 2025-01-16 19:04:28 by ysuliman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_meals(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->num_philos)
	{
		if (philo[i].meal_count == philo->data->number_meals)
			return (1);
		i++;
	}
	return (0);
}

int	check_dead(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->num_philos)
	{
		if ((ft_get_time() - philo[i].last_meal) <= philo->data->time_to_die)
			return (1);
		i++;
	}
	return (0);
}
void	check_over(t_philo *philo)
{
	while (!philo->data->over)
	{
		if (check_meals(philo) && check_dead(philo))
			philo->data->over = 1;
	}
}
