/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:13:54 by kdaumont          #+#    #+#             */
/*   Updated: 2024/01/26 11:11:32 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Initialize data structure
@param data -> t_data struct pointer
*/
void	init_data(t_data *data)
{
	data->nb_philo = 0;
	data->die_time = -1;
	data->eat_time = -1;
	data->sleep_time = -1;
	data->eat_count = -1;
	data->threads = NULL;
	data->philo = NULL;
	data->forks = NULL;
}

/* Initialize philo structure
@param philo -> t_philo struct pointer
@param id -> philosopher's id
*/
void	init_philo(t_philo *philo, int id)
{
	philo->id = id;
	philo->is_dead = 0;
	philo->is_eat = 0;
	philo->is_think = 0;
	philo->nb_eat = 0;
	philo->last_eat = 0;
}

/* Initialize in data structure the philo, threads & forks
@param data -> t_data struct pointer
*/
void init_all(t_data *data)
{
	t_philo *philo;
	int i;

	i = -1;
	philo = malloc(data->nb_philo * sizeof(t_philo));
	if (!philo)
		return (NULL);
	while (++i < data->nb_philo)
		init_philo(&philo[i], i);
	data->philo = philo;
	init_forks(data);
	init_threads(data);
}

/* Initialize forks with mutex
@param data -> t_data struct pointer
*/
void init_forks(t_data *data)
{
	pthread_mutex_t *forks;
	int i;

	i = -1;
	forks = malloc(data->nb_philo * sizeof(pthread_mutex_t));
	if (!forks)
		return (NULL);
	while (++i < data->nb_philo)
		pthread_mutex_init(&forks[i], NULL);
	data->forks = forks;
}

/* Initialize threads
@param data -> t_data struct pointer
*/
void	init_threads(t_data *data)
{
	pthread_t *threads;
	
	threads = malloc(data->nb_philo * sizeof(pthread_t));
	if (!threads)
		return (NULL);
	data->threads = threads;
}
