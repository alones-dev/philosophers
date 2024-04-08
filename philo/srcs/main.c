/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:27:03 by kdaumont          #+#    #+#             */
/*   Updated: 2024/04/08 09:40:03 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Routine for the philo threads
@param args -> t_philo struct pointer
@return NULL
*/
void	*routine(void *args)
{
	t_philo	*philo;
	t_data	*data;
	int		fork1;
	int		fork2;

	philo = (t_philo *)args;
	data = (t_data *)philo->data;
	fork1 = philo->id;
	fork2 = philo->id + 1;
	if (fork2 >= data->nb_philo)
		fork2 = 0;
	if (data->nb_philo == 1)
	{
		print_state(data, CYAN, philo, "has taken a fork");
		ft_usleep(philo, data->die_time);
		print_state(data, RED, philo, "died");
		return (NULL);
	}
	while (1)
	{
		if (philo_loop(philo, data, fork1, fork2) == -1)
			break ;
	}
	return (NULL);
}

/* Routine for the die thread (check if a philo is dead)
@param args -> t_data struct pointer
@return NULL
*/
void	*die_routine(void *args)
{
	t_data	*data;

	data = (t_data *)args;
	(void)data;
	return (NULL);
}

/* Call all init functions & init print mutex
@param data -> t_data struct pointer
@param print -> print mutex
@param ac -> arguments count
@param av -> arguments values
*/
void	initialize(t_data *data, pthread_mutex_t *print, int ac, char **av)
{
	init_data(data);
	check_args(ac, av, data);
	init_all(data);
	pthread_mutex_init(print, NULL);
	data->print = print;
}

/* Main function */
int	main(int ac, char **av)
{
	t_data			data;
	pthread_t		die;
	pthread_mutex_t	print;
	int				i;

	i = -1;
	initialize(&data, &print, ac, av);
	pthread_create(&die, NULL, &die_routine, (void *)&data);
	while (++i < data.nb_philo)
	{
		pthread_create(&data.threads[i], NULL, &routine,
			&data.philo[i]);
		ft_usleep(&data.philo[i], !(i % 2));
	}
	i = -1;
	while (++i < data.nb_philo)
		pthread_join(data.threads[i], NULL);
	return (0);
}
