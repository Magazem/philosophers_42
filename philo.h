/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysuliman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:30:25 by ysuliman          #+#    #+#             */
/*   Updated: 2024/12/16 10:45:00 by ysuliman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "struct.h"
# include <fcntl.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DEAD "died"

void	*routine(void *arg);
int		check_args(int argc, char *argv[]);
void	initiate_data(int argc, char **argv, t_data *data);
void	error_manager(char *text, t_philo *philo);
long	ft_atol(const char *str);
long	ft_get_time(void);
int		ft_usleep(long int time);
void	initiate_mutex(t_data *data);
void	initiate_program(t_data *data);
void	*monitor(void *philo_pointer);

#endif