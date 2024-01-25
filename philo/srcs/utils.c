/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:45:38 by kdaumont          #+#    #+#             */
/*   Updated: 2024/01/25 09:49:38 by kdaumont         ###   ########.fr       */
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
int error_exit(char *msg)
{
	printf("Error\n%s\n", msg);
	return (0);
}