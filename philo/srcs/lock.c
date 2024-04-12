/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 08:55:00 by kdaumont          #+#    #+#             */
/*   Updated: 2024/04/12 08:56:38 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Lock mutexes of fork to skip deadlocks
@param philo -> t_philo struct pointer
@param fork1 -> first fork index
@param fork2 -> second fork index
@param state -> 1 for even, 2 for odd
*/
void	fork_lock(t_philo *philo, int fork1, int fork2, int state)
{
	if (state == 1)
	{
		if (philo->id % 2 == 0)
			pthread_mutex_lock(&philo->data->forks[fork1]);
		else
			pthread_mutex_lock(&philo->data->forks[fork2]);
	}
	else if (state == 2)
	{
		if (philo->id % 2 == 0)
			pthread_mutex_lock(&philo->data->forks[fork2]);
		else
			pthread_mutex_lock(&philo->data->forks[fork1]);
	}
}

/* Unlock mutexes of fork to skip deadlocks
@param philo -> t_philo struct pointer
@param fork1 -> first fork index
@param fork2 -> second fork index
*/
void	fork_unlock(t_philo *philo, int fork1, int fork2)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(&philo->data->forks[fork1]);
		pthread_mutex_unlock(&philo->data->forks[fork2]);
	}
	else
	{
		pthread_mutex_unlock(&philo->data->forks[fork2]);
		pthread_mutex_unlock(&philo->data->forks[fork1]);
	}
}
