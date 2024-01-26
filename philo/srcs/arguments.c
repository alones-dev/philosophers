/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:43:54 by kdaumont          #+#    #+#             */
/*   Updated: 2024/01/26 10:56:06 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Check if the character is a number
@param c -> checked character
@return :
	- 0 : not number
	- 1 : valid number
*/
int	is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/* Check if the arguments amount is valid (min. 5, max. 6)
@param ac -> main arguments count
@return :
	- 0 : invalid arguments amount
	- 1 : good arguments amount
*/
int	check_amount(int ac)
{
	if (ac < 5)
		return (error_exit("Minimum arguments amount must be 5"));
	if (ac > 6)
		return (error_exit("Maximum arguments amount must be 6"));
	return (1);
}

/* Check if the arguments are valid (must be integer only)
@param ac -> main arguments count
@param av -> main arguments values
@return :
	- 0 : arguments invalid
	- 1 : arguments ok
*/
int	check_args(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		while (av[i][j])
		{
			if (!is_number(av[i][j]))
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

/* Check if the integers get a good value
@param av -> main arguments values
@return :
	- 0 : bad value
	- 1 : all good value
*/
int	check_numbers(char **av, t_data *data)
{
	int	i;
	int	nb;

	i = 0;
	while (av[++i])
	{
		nb = ft_atoi(av[i]);
		if (nb <= 0)
			return (error_exit("Arguments must be positive"));
		if (i == 1)
		{
			if (nb < 1)
				return (error_exit("Amount of philo must be > 0"));
			data->nb_philo = nb;
		}
		if (i == 2)
			data->die_time = nb;
		if (i == 3)
			data->eat_time = nb;
		if (i == 4)
			data->sleep_time = nb;
		if (i == 5)
			data->eat_count = nb;
	}
	return (1);
}
