/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysuliman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:46:47 by ysuliman          #+#    #+#             */
/*   Updated: 2024/12/05 13:52:01 by ysuliman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error_manager(char *text, t_philo *philo)
{
	long	i;
	long	num;

	i = 0;
	num = philo->data->num_philos;
	printf("%s", text);
	if (philo)
	{
		free(philo->data->forks);
		free(philo->data->death);
		if (philo->data)
			free(philo->data);
		while (i < num)
			free(philo[i++].tid);
		free(philo->tid);
		i = 0;
		while (i < num)
		{
			free(philo[i].left_fork);
			free(philo[i].right_fork);
		}
		while (i < num)
			free(philo[i++]);
	}
	return (0);
}

long	ft_get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

long	ft_atol(const char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while ((str && str[i] == ' ') || (str && (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str && str[i] && str[i] >= '0' && str[i] <= '9')
		result = result * 10 + (str[i++] - '0');
	return (sign * result);
}

int	ft_usleep(long int time)
{
	long int	start_time;

	start_time = get_time();
	while ((get_time() - start_time) < time)
		usleep(150);
	return (1);
}
