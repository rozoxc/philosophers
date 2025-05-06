/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:58:01 by ababdoul          #+#    #+#             */
/*   Updated: 2025/05/06 03:44:34 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void sleep_and_think(s_philo *philo)
{
    s_data *data;
    
    data = philo->data;
    
    // Sleep phase
    print_status(philo, "is sleeping");
    ft_sleep(data->time_to_sleep);
    
    // Check if a philosopher died during sleep
    pthread_mutex_lock(&data->monitor_mutex);
    if (data->death)
    {
        pthread_mutex_unlock(&data->monitor_mutex);
        return;
    }
    pthread_mutex_unlock(&data->monitor_mutex);
    
    // Think phase
    print_status(philo, "is thinking");
    
    // Add a small delay for even-numbered philosophers to prevent deadlock
    if (philo->id % 2 == 0 && data->philosopher_count > 2)
        ft_sleep(10);
}
void eat(s_philo *philo)
{
    s_data *data = philo->data;

    print_status(philo, "is eating");
    pthread_mutex_lock(&data->monitor_mutex);
    philo->last_meal_time = get_time();
    philo->meals_eaten++;
    pthread_mutex_unlock(&data->monitor_mutex);
    ft_sleep(data->time_to_eat);
}

void take_fork(s_data *data, s_philo *philo)
{
    (void)data;
    pthread_mutex_lock(philo->right_fork);
    print_status(philo, "taken right fork");
    pthread_mutex_lock(philo->left_fork);
    print_status(philo, "taken left fork");   
    pthread_mutex_unlock(philo->right_fork);
    pthread_mutex_unlock(philo->left_fork);
    // pthread_mutex_lock(&data->dead_mutex);
    // if (data->death)
    // {
    //     pthread_mutex_unlock(&data->dead_mutex);
    //     return;
    // }
    // pthread_mutex_unlock(&data->dead_mutex);
}
void put_forks(s_philo *philos)
{
    pthread_mutex_unlock(philos->right_fork);
    print_status(philos, "put right fork");
    pthread_mutex_unlock(philos->left_fork);
    print_status(philos, "put left fork");
}
