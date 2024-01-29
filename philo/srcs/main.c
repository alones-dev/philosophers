/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:27:03 by kdaumont          #+#    #+#             */
/*   Updated: 2024/01/29 10:50:49 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *args)
{
	t_philo *philo;
	t_data	*data;

	philo = (t_philo *)args;
	data = (t_data *)philo->data;
	// printf("%lld\n", get_time());
	printf("%d\n", philo->id);
	return (NULL);
}

/* Main function */
int	main(int ac, char **av)
{
	t_data	data;
	int		i;

	i = -1;
	init_data(&data);
	check_args(ac, av, &data);
	init_all(&data);
	while (++i < data.nb_philo)
		pthread_create(&data.threads[i], NULL, &routine,
			(void *)&data.philo[i]);
	i = -1;
	while (++i < data.nb_philo)
		pthread_join(data.threads[i], NULL);
	return (0);
}
