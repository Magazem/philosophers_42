/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysuliman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 20:02:09 by ysuliman          #+#    #+#             */
/*   Updated: 2024/12/05 16:03:58 by ysuliman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "philo.h"
# include <pthread.h>

typedef struct s_data
{
	long			num_philos;
	long			time_to_eat;
	long			time_to_sleep;
	long			time_to_die;
	long			number_meals;
	long			start_time;
	int				ready;
	int				over;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*death;
}					t_data;

typedef struct s_philo
{
	pthread_t		*tid;
	int				id;
	int				dead;
	int				last_meal;
	int				eat_count;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_data			*data;
}					t_philo;

#endif // STRUCT_H