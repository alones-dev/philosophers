/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 13:51:22 by kdaumont          #+#    #+#             */
/*   Updated: 2024/04/12 09:21:07 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Unlock one or two forks for data races
@param data -> t_data struct pointer
@param fork1 -> first fork index
@param fork2 -> second fork index
@param state -> 1 for two forks, 0 for one fork
*/
int	is_dead(t_philo *philo, int fork1, int fork2, int i)
{
	pthread_mutex_lock(&philo->data->die);
	if (philo->data->stop)
	{
		if (philo->id % 2 == 0)
		{
			if (i >= 1)
				pthread_mutex_unlock(&philo->data->forks[fork1]);
			if (i == 2)
				pthread_mutex_unlock(&philo->data->forks[fork2]);
		}
		else
		{
			if (i >= 1)
				pthread_mutex_unlock(&philo->data->forks[fork2]);
			if (i == 2)
				pthread_mutex_unlock(&philo->data->forks[fork1]);
		}
		pthread_mutex_unlock(&philo->data->die);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->die);
	return (0);
}

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
	if (is_dead(philo, 0, 0, 0) == 1)
		return (-1);
	fork_lock(philo, fork1, fork2, 1);
	print_state(data, CYAN, philo, "has taken a fork");
	fork_lock(philo, fork1, fork2, 2);
	print_state(data, CYAN, philo, "has taken a fork");
	print_state(data, GREEN, philo, "is eating");
	pthread_mutex_lock(&data->eating);
	philo->nb_eat++;
	pthread_mutex_unlock(&data->eating);
	pthread_mutex_lock(&data->eat);
	philo->last_eat = get_curtime(data);
	pthread_mutex_unlock(&data->eat);
	if (is_dead(philo, fork1, fork2, 2) == 1)
		return (-1);
	ft_usleep(philo, data, data->eat_time);
	fork_unlock(philo, fork1, fork2);
	if (is_dead(philo, 0, 0, 0) == 1)
		return (-1);
	print_state(data, PURPLE, philo, "is sleeping");
	ft_usleep(philo, data, data->sleep_time);
	if (is_dead(philo, 0, 0, 0) == 1)
		return (-1);
	print_state(data, YELLOW, philo, "is thinking");
	return (0);
}

/* Check if all philo have eaten the number of time required (for last argument)
@param data -> t_data struct pointer
@return :
	- 1 : all philo have eaten the number of time required
	- 0 : not all philo have eaten the number of time required
*/
int	check_eat_count(t_data *data)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	if (data->eat_count <= 0)
		return (0);
	while (++i < data->nb_philo)
	{
		pthread_mutex_lock(&data->eating);
		if (data->philo[i].nb_eat >= data->eat_count)
			count++;
		pthread_mutex_unlock(&data->eating);
	}
	if (count == data->nb_philo)
		return (1);
	return (0);
}

/* Check if a philo is dead
@param data -> t_data struct pointer
@return :
	- 1 : a philo is dead
	- 0 : all philo are alive
*/
int	check_dead_philo(t_data *data)
{
	int	i;
	int	all_eat;
	int	die_time;

	i = -1;
	all_eat = check_eat_count(data);
	pthread_mutex_lock(&data->eat);
	die_time = get_curtime(data) - data->philo->last_eat;
	pthread_mutex_unlock(&data->eat);
	if (all_eat || die_time >= data->die_time)
	{
		if (!all_eat)
			print_state(data, RED, data->philo, "died");
		pthread_mutex_lock(&data->die);
		data->stop = 1;
		pthread_mutex_unlock(&data->die);
		return (1);
	}
	return (0);
}
