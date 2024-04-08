/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 13:51:05 by kdaumont          #+#    #+#             */
/*   Updated: 2024/04/08 16:13:05 by kdaumont         ###   ########.fr       */
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
void	ft_usleep(t_philo *philo, long long time)
{
	long long start;

	start = get_time();
	while (get_time() < start + time)
	{
		if (philo->dead)
			break ;
		usleep(500);
	}
}
