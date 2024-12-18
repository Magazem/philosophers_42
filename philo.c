/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysuliman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:31:13 by ysuliman          #+#    #+#             */
/*   Updated: 2024/12/05 17:02:32 by ysuliman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (check_args(ac, av))
	{
		initiate_data(ac, av, &data);
		initiate_program(&data);
	}
	return (0);
}
