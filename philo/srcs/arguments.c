/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:43:54 by kdaumont          #+#    #+#             */
/*   Updated: 2024/01/19 14:17:18 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int 	check_args(int ac, char **av)
{
	int	i;
	int j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		while (av[i][j])
		{
			if (!is_number(av[i][j]))
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	i = 1;
	while (av[i])
	{
		if (ft_atoi(av[i]) < 0)
			return (0);
		i++;
	}
	return (1);
}
