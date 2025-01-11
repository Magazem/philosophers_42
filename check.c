/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysuliman <ysuliman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:14:35 by ysuliman          #+#    #+#             */
/*   Updated: 2024/12/05 16:59:27 by ysuliman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(int argc, char *argv[])
{
	int	i;

	i = 0;
	if (argc == 5 || argc == 6)
	{
		if (ft_atol(argv[1]) <= 0)
			return (printf("needs one philosopher at least"), 0);
		while (i++ < argc)
		{
			if (ft_atol(argv[i]) <= 0)
				return (printf("value can't be smaller or equal to zero"), 0);
		}
	}
	else
		return (printf("faulty arguments input"), 0);
	return (1);
}
