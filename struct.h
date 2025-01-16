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
	pthread_mutex_t	*lock;
}					t_data;

typedef struct s_philo
{
	pthread_t		tid;
	long			meal_count;
	long			last_meal;
	int				id;
	int				dead;
	t_data			*data;
}					t_philo;

#endif