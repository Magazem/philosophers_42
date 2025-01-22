/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysuliman <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-15 14:03:59 by ysuliman          #+#    #+#             */
/*   Updated: 2025-01-15 14:03:59 by ysuliman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include "struct.h"
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

// Shorts
# define Alive "is alive"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define FORK "has taken a fork"
# define EAT "is eating"
# define DEAD "died"

void	initiate_data(int ac, char **av, t_data *data);
long	ft_atol(const char *str);
long	ft_get_time(void);
void	*routine(void *arg);
void	initiate_philo(t_data *data);
void	check_over(t_philo *philo);
int		ft_usleep(long time);
#endif