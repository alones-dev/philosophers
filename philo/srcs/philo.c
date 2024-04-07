/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 13:51:22 by kdaumont          #+#    #+#             */
/*   Updated: 2024/04/07 15:07:35 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Function to make a philo eat, sleep and think, all loop in the routine
@param philo -> t_philo struct pointer
@param data -> t_data struct pointer
@param fork1 -> first fork index
@param fork2 -> second fork index
@return :
	- 1 : philo is dead
	- 0 : philo is alive
*/
int	philo_loop(t_philo *philo, t_data *data, int fork1, int fork2)
{
	printf("debug 1\n");
	pthread_mutex_lock(&data->forks[fork1]);
	print_state(data, CYAN, philo, "has taken a fork");
	pthread_mutex_lock(&data->forks[fork2]);
	printf("debug 2\n");
	print_state(data, CYAN, philo, "has taken a fork");
	print_state(data, GREEN, philo, "is eating");
	philo->nb_eat++;
	philo->last_eat = get_curtime(data);
	printf("debug 3\n");
	ft_usleep(philo, data->eat_time);
	pthread_mutex_unlock(&data->forks[fork1]);
	pthread_mutex_unlock(&data->forks[fork2]);
	printf("debug 4\n");
	print_state(data, PURPLE, philo, "is sleeping");
	ft_usleep(philo, data->sleep_time);
	print_state(data, YELLOW, philo, "is thinking");
	printf("debug 5\n");
	return (0);
}
