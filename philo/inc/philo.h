/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:27:35 by kdaumont          #+#    #+#             */
/*   Updated: 2024/01/28 21:06:54 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	int				id;
	int				is_dead;
	int				is_eat;
	int				is_think;
	int				is_sleep;
	int				nb_eat;
	long long		last_eat;
	struct t_data	*data;
}					t_philo;

typedef struct s_data
{
	int				nb_philo;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				eat_count;
	pthread_t		*threads;
	t_philo			*philo;
	pthread_mutex_t	*forks;
}					t_data;

int					ft_atoi(const char *nptr);
int					check_amount(int ac);
int					check_args(int ac, char **av, t_data *data);
int					check_numbers(char **av, t_data *data);
int					error_exit(char *msg);
void				init_data(t_data *data);
void				init_philo(t_philo *philo, t_data *data, int id);
void				init_forks(t_data *data);
void				init_threads(t_data *data);

#endif