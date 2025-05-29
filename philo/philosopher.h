/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:39:19 by ababdoul          #+#    #+#             */
/*   Updated: 2025/05/29 22:43:13 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <limits.h>
# include <stdbool.h>

typedef enum t_type_mutex
{
	INIT,
	LOCK,
	UNLOCK,
	DESTROY,
}	t_type_mutex;

typedef enum type_thread
{
	CREAT,
	JOIN
}	t_type_thread;

typedef struct t_data
{
	int				philosopher_count;
	int				time_to_die;
	int				time_to_sleep;
	int				time_to_eat;
	int				time_to_think;
	int				start_time;
	int				all_ate;
	int				death;
	int				is_eating;
	int				number_of_meals;
	pthread_mutex_t	dead_mutex;
	pthread_mutex_t	*forks;
	pthread_mutex_t	monitor_mutex;
	pthread_t		monitor_thread;
}	t_data;

typedef struct t_philo
{
	int				id;
	int				meals_eaten;
	int				last_meal_time;
	pthread_t		thread;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	t_data			*data;
}	t_philo;

// utils functions 
int		ft_atoi(const char *str);
int		print_status(t_philo *philo, char *message);
int		parse_input(char **av);
void	cleanup(t_data *data, t_philo *philo);
//time functions
int		get_time(void);
void	ft_sleep(int miliseconde, t_data *data);
//initialization functions
int		init_data(t_data *data, int ac, char **av);
int		init_philo(t_philo **philo, t_data *data);
int		init_forks(t_data *data);

//simulations functions
void	*philosopher_routine(void *arg);
int		start_simulation(t_philo *philos, t_data *data);
void	*monitor_routine(void *arg);
int		take_fork(t_data *data, t_philo *philo);
int		put_forks(t_philo *philos);
int		sleep_and_think(t_philo *philo);
int		eat(t_philo *philo);
int		ft_isdigit(int c);
int		safe_mutex(pthread_mutex_t *mutex, t_type_mutex type);
int		safe_thread(pthread_t *thread,
			t_type_thread type, void *(*f)(void *), t_philo *philos);

#endif
