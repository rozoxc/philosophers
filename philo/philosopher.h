/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:39:19 by ababdoul          #+#    #+#             */
/*   Updated: 2025/02/25 01:22:30 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H

#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

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

} s_data;

typedef struct t_philo
{
    int id;
    int meals_eaten;
    long last_meal;
    pthread_t pid;
    pthread_mutex_t right_fork;
    pthread_mutex_t left_fork;
    s_data          *data;
    
} s_philo;

// utils functions 
int	ft_atoi(const char *str);

//time functions
long    get_time();
void    ft_sleep(long miliseconde);

#endif