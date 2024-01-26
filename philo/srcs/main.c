/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:27:03 by kdaumont          #+#    #+#             */
/*   Updated: 2024/01/26 10:54:07 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data *data;
	
	if (!check_amount(ac) || !check_args(ac, av))
		return (1);
	init_data(&data);
	if (!check_numbers(av, &data))
		return (1);
	return (0);
}