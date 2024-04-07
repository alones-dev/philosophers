/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:45:38 by kdaumont          #+#    #+#             */
/*   Updated: 2024/04/07 15:03:10 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Convert a str in integer
@param nptr -> str to convert
@return -> result of the convert
*/
int	ft_atoi(const char *nptr)
{
	int	i;
	int	nbr;
	int	sign;
	int	count;

	i = 0;
	nbr = 0;
	sign = 1;
	count = 0;
	while (nptr[i] == ' ' || ('\t' <= nptr[i] && nptr[i] <= '\r'))
		i++;
	while ((nptr[i] == '+' || nptr[i] == '-') && count < 1)
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
		count++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nbr = nbr * 10 + nptr[i] - '0';
		i++;
	}
	return (nbr * sign);
}

/* Print the error message and return 0
@param msg -> error message
@return 0
*/
int	error_exit(char *msg)
{
	printf("Error: %s\n", msg);
	return (0);
}

/* Free all mallocs in data structure
@param data -> t_data struct pointer
*/
void	free_all(t_data *data)
{
	int	i;

	i = -1;
	if (data->philo)
		free(data->philo);
	if (data->threads)
		free(data->threads);
	if (data->forks)
	{
		while (++i < data->nb_philo)
			pthread_mutex_destroy(&data->forks[i]);
		free(data->forks);
	}
}

void	print_state(t_data *data, char *color, t_philo *philo, char *msg)
{
	pthread_mutex_lock(data->print);
	if (!philo->dead)
		printf("[%lld] %s%d %s%s\n", get_curtime(data), color, philo->id, msg,
			DEFAULT);
	pthread_mutex_unlock(data->print);
}