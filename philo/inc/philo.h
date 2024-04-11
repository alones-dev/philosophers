/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:27:35 by kdaumont          #+#    #+#             */
/*   Updated: 2024/04/11 14:01:15 by kdaumont         ###   ########.fr       */
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

# define DEFAULT "\033[m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define CYAN "\033[1;36m"
# define PURPLE "\033[1;35m"
# define YELLOW "\033[0;33m"

typedef struct s_philo
{
	int				id;
	int				nb_eat;
	int				dead;
	long long		last_eat;
	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	int				nb_philo;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				eat_count;
	long long		start_time;
	pthread_t		*threads;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*print;
	pthread_mutex_t	die;
}					t_data;

/* utils.c */
int					ft_atoi(const char *nptr);
int					error_exit(char *msg, t_data *data);
void				free_all(t_data *data);
void				print_state(t_data *data, char *color, t_philo *philo,
						char *msg);

/* time.c */
long long			get_curtime(t_data *data);
long long			get_time(void);
void				ft_usleep(t_philo *philo, t_data *data, long long time);

/* arguments.c */
int					check_amount(int ac, t_data *data);
int					check_args(int ac, char **av, t_data *data);
int					check_numbers(char **av, t_data *data);

/* init.c */
void				init_data(t_data *data);
void				init_philo(t_philo *philo, t_data *data, int id);
void				init_forks(t_data *data);
void				init_threads(t_data *data);
void				init_all(t_data *data);

/* philo.c */
int					philo_loop(t_philo *philo, t_data *data, int fork1,
						int fork2);
int					check_dead_philo(t_data *data);

#endif
