/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 21:56:49 by ababdoul          #+#    #+#             */
/*   Updated: 2025/03/15 15:55:25 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void *philosopher_routine(void *arg)
{
    s_data *data;
    s_philo *philo;
    
    philo = (s_philo *)arg;
    if (!philo)
        return NULL;
    data = philo->data;
    if (!data)
        return NULL;
    if (data->philosopher_count == 0)
    {
        printf("there is no philosopher !!\n");
        return (NULL);
    }
    if (data->philosopher_count == 1)
    {
        print_status(philo, "has taken a fork");
        ft_sleep(data->time_to_die);
        print_status(philo, "died");
        return (NULL);
    }
    else if (data->philosopher_count > 1)
        algo_philo(philo, data);
    return (NULL);
}

int     start_simulation(s_philo *philos, s_data *data)
{
    int i;

    i = 0;
    while (i < data->philosopher_count)
    {
        philos[i].last_meal_time = get_time();
        if (pthread_create(&philos[i].thread, NULL, philosopher_routine, &philos[i]) != 0)
            return (0);
        pthread_join(philos[i].thread, NULL);
        i++;
    }
    return (1);
}