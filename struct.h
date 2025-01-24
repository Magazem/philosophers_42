/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysuliman <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-15 14:03:50 by ysuliman          #+#    #+#             */
/*   Updated: 2025-01-15 14:03:50 by ysuliman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef STRUCT_H
# define STRUCT_H
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
	long			full;
	pthread_mutex_t	*lock;
	pthread_mutex_t	*meals;
	pthread_mutex_t	*forks;
}					t_data;

typedef struct s_philo
{
	pthread_t		tid;
	long			meal_count;
	long			last_meal;
	int				id;
	int				dead;
	t_data			*data;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}					t_philo;

#endif