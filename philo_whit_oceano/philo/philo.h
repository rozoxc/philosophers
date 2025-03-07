/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 04:15:28 by ababdoul          #+#    #+#             */
/*   Updated: 2025/03/07 05:58:49 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
#include <stdbool.h>

typedef enum status
{
    eating,
    sleeping,
    thinking,
    take_first_fork,
    take_seconde_fork,
    died,
}s_status;

typedef enum time_code
{
    seconde,
    miliseconde,
    microseconde,
} s_time;

typedef enum mutex_code
{
    lock,
    unlock,
    init,
    create,
    destroy,
    join,
} m_code;
typedef struct philo s_philo; // let compiler know that this struct it will exist

typedef struct fork{
    pthread_mutex_t fork;
    int id_fork;
} s_forks;

typedef struct data{
    long philo_numbers;
    long time_to_die;
    long timt_to_eat;
    long time_to_sleep;
    long number_of_meals;
    long start_simulation;
    bool end_of_simulation;
    bool all_thread_ready;
    pthread_mutex_t table_mutex;
    pthread_mutex_t write_mutex;
    s_forks *forks;
    s_philo *philos;
} s_data;

typedef struct  philo{
    int id;
    long meal_eaten;
    bool full;
    long last_meal_time;
    s_forks *first_fork;
    s_forks *second_fork;
    pthread_t thread_id;
    s_data *data;
} s_philo;

void error_print(char *message);
void parse_input(s_data *data , char **av);
long ft_atoi(char *str);
int is_digit(char *str);

void init_data(s_data *data);
void start_simulation(s_data *data);
void *philo_routine(void *data);

void safe_mutex(pthread_mutex_t *mutex,m_code mcode);

//getters and setters functions 
void set_bool(pthread_mutex_t *mutex, bool *dest, bool value);
bool get_bool(pthread_mutex_t *mutex, bool *value);
void set_long(pthread_mutex_t *mutex, long *dest, long value);
long get_long(pthread_mutex_t *mutex, long *value);
bool  simulation_done(s_data *data);

void wait_threads(s_data *data);
long ft_time(s_time time_code);
void ft_usleep(long usec, s_data *data);


#endif 