/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysuliman <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-15 14:04:03 by ysuliman          #+#    #+#             */
/*   Updated: 2025-01-15 14:04:03 by ysuliman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(int argc, char *argv[])
{
	int	i;

	i = 2;
	if (argc == 5 || argc == 6)
	{
		if (ft_atol(argv[1]) <= 0)
			return (printf("needs one philosopher at least"), 0);
		while (i < argc)
		{
			if (ft_atol(argv[i]) <= 0)
				return (printf("value can't be smaller or equal to zero"), 0);
			i++;
		}
	}
	else
		return (printf("faulty arguments input"), 0);
	return (1);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (check_args(ac, av))
	{
		initiate_data(ac, av, &data);
		initiate_philo(&data);
	}
}
