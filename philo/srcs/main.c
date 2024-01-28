/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:27:03 by kdaumont          #+#    #+#             */
/*   Updated: 2024/01/28 21:10:52 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	routine(void *args)
{
	
	return (0);
}

/* Main function */
int	main(int ac, char **av)
{
	t_data	data;
	int		i;

	i = -1;
	init_data(&data);
	check_args(ac, av, &data);
	while (++i < data.nb_philo)
		pthread_create(&data.threads[i], NULL, &routine,
			(void *)&data.philo[i]);
	return (0);
}
