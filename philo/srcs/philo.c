/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 13:51:22 by kdaumont          #+#    #+#             */
/*   Updated: 2024/04/11 13:55:31 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Unlock one or two forks for data races
@param data -> t_data struct pointer
@param fork1 -> first fork index
@param fork2 -> second fork index
@param state -> 1 for two forks, 0 for one fork
*/
void	unlockm(t_data *data, int fork1, int fork2, int state)
{
	if (state == 1)
	{
		pthread_mutex_unlock(&data->forks[fork1]);
		pthread_mutex_unlock(&data->forks[fork2]);
	}
	else
		pthread_mutex_unlock(&data->forks[fork1]);
}

/* Check if the variable dead is set to 1
@param philo -> t_philo struct pointer
@param data -> t_data struct pointer
@return :
	- 1 : philo is dead
	- 0 : philo is alive
*/
int	is_dead(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&data->die);
	if (philo->dead == 1)
	{
		pthread_mutex_unlock(&data->die);
		return (1);
	}
	pthread_mutex_unlock(&data->die);
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
	if (is_dead(philo, data) == 1)
		return (-1);
	pthread_mutex_lock(&data->forks[fork1]);
	if (is_dead(philo, data) == 1)
		return (unlockm(data, fork1, fork2, 0), -1);
	print_state(data, CYAN, philo, "has taken a fork");
	pthread_mutex_lock(&data->forks[fork2]);
	if (is_dead(philo, data) == 1)
		return (unlockm(data, fork1, fork2, 1), -1);
	print_state(data, CYAN, philo, "has taken a fork");
	(print_state(data, GREEN, philo, "is eating"), philo->nb_eat++);
	philo->last_eat = get_curtime(data);
	ft_usleep(philo, data->eat_time);
	if (is_dead(philo, data) == 1)
		return (unlockm(data, fork1, fork2, 1), -1);
	unlockm(data, fork1, fork2, 1);
	if (is_dead(philo, data) == 1)
		return (-1);
	print_state(data, PURPLE, philo, "is sleeping");
	ft_usleep(philo, data->sleep_time);
	if (is_dead(philo, data) == 1)
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
		if (data->philo[i].nb_eat >= data->eat_count)
			count++;
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
	die_time = get_curtime(data) - data->philo->last_eat;
	if (all_eat || die_time >= data->die_time)
	{
		pthread_mutex_lock(&data->die);
		while (++i < data->nb_philo)
			data->philo[i].dead = 1;
		pthread_mutex_unlock(&data->die);
		if (!all_eat)
			print_state(data, RED, data->philo, "died");
		return (1);
	}
	return (0);
}
