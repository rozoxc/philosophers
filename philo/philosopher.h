/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:39:19 by ababdoul          #+#    #+#             */
/*   Updated: 2025/05/05 03:46:29 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H

#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <limits.h>


typedef struct t_data
{
    int philosopher_count;
    int time_to_die;
    int time_to_sleep;
    int time_to_eat;
    int time_to_think;
    long start_time; 
    int all_ate; // wax kamlin klaw
    int death; //wax l philo mat
    int number_of_meals; //optional
    pthread_mutex_t write_mutex;
    pthread_mutex_t dead_mutex;
    pthread_mutex_t *forks;
    pthread_mutex_t monitor_mutex;
    pthread_t monitor_thread;

} s_data;

typedef struct t_philo
{
    int id;
    int meals_eaten;
    long last_meal_time;
    pthread_t thread;
    pthread_mutex_t *right_fork;
    pthread_mutex_t *left_fork;
    s_data          *data;
    
} s_philo;

// utils functions 
int	ft_atoi(const char *str);
void print_status(s_philo *philo, char *message);
int parse_input(s_data *data);

//time functions
long    get_time();
void    ft_sleep(long miliseconde);

//initialization functions
int init_data(s_data *data, int ac, char **av);
int init_philo(s_philo **philo, s_data *data);
int init_forks(s_data *data);

//simulations functions
void    *philosopher_routine();
int     start_simulation(s_philo *philos, s_data *data);
void    check_death(s_philo *philos, s_data *data);
void    stop_simulation(s_philo *philos, s_data *data);
void    algo_philo(s_philo *philo, s_data *data);
void *monitor_routine(void *arg);
void take_fork(s_data *data, s_philo *philo);
void put_forks(s_philo *philos);
void sleep_and_think(s_philo *philos);
void eat(s_philo *philo);

#endif