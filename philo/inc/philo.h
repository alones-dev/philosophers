/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:27:35 by kdaumont          #+#    #+#             */
/*   Updated: 2024/01/19 14:12:04 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define USAGE_CMD "Usage: ./philo nb_philo time_to_die time_to_eat time_to_sleep [amount_eat_philo]\n"
# define BAD_ARGS "Bad arguments: arguments must be positive integers\n"

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

int	ft_atoi(const char *nptr);
int	check_args(int ac, char **av);

#endif