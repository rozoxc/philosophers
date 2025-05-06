/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 21:56:49 by ababdoul          #+#    #+#             */
/*   Updated: 2025/05/06 03:42:57 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void *philosopher_routine(void *arg)
{
    s_philo *philo = (s_philo *)arg;
    s_data *data = philo->data;

    if (data->philosopher_count == 1)
    {
        pthread_mutex_lock(philo->right_fork);
        print_status(philo, "has taken a fork");
        ft_sleep(data->time_to_die);
        print_status(philo, "died");
        pthread_mutex_unlock(philo->right_fork);
        return NULL;
    }
    if (philo->id % 2 == 0)
        ft_sleep(data->time_to_eat / 2);
    while (1)
    {
        pthread_mutex_lock(&data->dead_mutex);
        if (data->death)
        {
            pthread_mutex_unlock(&data->dead_mutex);
            break;
        }
        pthread_mutex_unlock(&data->dead_mutex);
        
        take_fork(data, philo);
        pthread_mutex_lock(&data->dead_mutex);
        if (data->death)
        {
            pthread_mutex_unlock(&data->dead_mutex);
            break;
        }
        pthread_mutex_unlock(&data->dead_mutex);
        eat(philo);
        pthread_mutex_lock(&data->dead_mutex);
        if (data->death)
        {
            pthread_mutex_unlock(&data->dead_mutex);
            break;
        }
        pthread_mutex_unlock(&data->dead_mutex);
        put_forks(philo);
        sleep_and_think(philo);
    }
    return NULL;
}

int start_simulation(s_philo *philos, s_data *data)
{
    int i;

    i = 0;
    data->start_time = get_time();
    while (i < data->philosopher_count)
    {
        philos[i].last_meal_time = get_time();
        if (pthread_create(&philos[i].thread, NULL, philosopher_routine, &philos[i]) != 0)
        {
            data->death = 1;
            return (0);
        }
        i++;
    }
    if (pthread_create(&data->monitor_thread, NULL, monitor_routine, philos) != 0)
    {
        data->death = 1;
        return (0);
    }
    i = 0;
    while (i < data->philosopher_count)
    {
        pthread_join(philos[i].thread, NULL);
        i++;
    }
    if (pthread_join(data->monitor_thread, NULL) != 0)
        return (0);
    return (1);
}
