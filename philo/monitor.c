/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:12:49 by ababdoul          #+#    #+#             */
/*   Updated: 2025/05/05 21:47:41 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void *monitor_routine(void *arg)
{
    s_philo *philo = (s_philo *)arg;
    s_data *data = philo->data;
    int done;
    int i;
    while (1)
    {
        done = 0;
        usleep(1000); // Check every 1ms (adjust as needed)
        
        pthread_mutex_lock(&data->monitor_mutex);
        if (data->death) // If someone already died, exit
        {
            pthread_mutex_unlock(&data->monitor_mutex);
            break;
        }
        // Check each philosopher's status
        for (i = 0; i < data->philosopher_count; i++)
        {
            // Check starvation
            if ((get_time() - philo[i].last_meal_time) > data->time_to_die)
            {
                data->death = 1;
                print_status(&philo[i], "died");
                pthread_mutex_unlock(&data->monitor_mutex);
                return (NULL);
            }
            
            // Check if this philosopher ate enough
            if (data->number_of_meals > 0 && philo[i].meals_eaten >= data->number_of_meals)
            {
                done++;
            }
        }
        
        // If all philosophers ate enough, end simulation
        if (data->number_of_meals > 0 && done == data->philosopher_count)
        {
            data->death = 1;
            pthread_mutex_unlock(&data->monitor_mutex);
            printf("All philosophers ate enough meals!\n");
            return (NULL);
        }
        
        pthread_mutex_unlock(&data->monitor_mutex);
    }
    return (NULL);
}
