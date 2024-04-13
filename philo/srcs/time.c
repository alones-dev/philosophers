/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 13:51:05 by kdaumont          #+#    #+#             */
/*   Updated: 2024/04/13 23:34:19 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Get actual time in milliseconds
@return time in milliseconds
*/
long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

/* Get current time, relative of start_time
@return current time
*/
long long	get_curtime(t_data *data)
{
	return (get_time() - data->start_time);
}

/* Usleep function with a long long time
@param philo -> t_philo struct pointer
@param time -> time in milliseconds
*/
void	ft_usleep(t_philo *philo, t_data *data, long long time)
{
	long long	start;

	start = get_time();
	while (get_time() < start + time)
	{
		pthread_mutex_lock(&data->die);
		if (philo->data->stop)
		{
			pthread_mutex_unlock(&data->die);
			break ;
		}
		pthread_mutex_unlock(&data->die);
		usleep(500);
	}
}
