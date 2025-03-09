/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 03:46:43 by ababdoul          #+#    #+#             */
/*   Updated: 2025/03/09 03:58:22 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *philo_routine(void *data)
{
    s_philo *philo;

    philo = (s_philo *)data;
    
    wait_threads(philo->data);
    while (!simulation_done(data))
    {
        if (philo->full)
            return ;
        eat(philo);
        // thinking(philo);
    }
    return NULL;
}
void start_simulation(s_data *data)
{
    int i;

    i = 0;
     if (data->number_of_meals == 0)
        return ;
    else if (data->philo_numbers == 1);
        //to_do later !!
    else
        while (i < data->philo_numbers)
        {
            safe_thread(&data->philos[i].thread_id ,philo_routine, data->philos[i], create);
            i++;
        }
    data->start_simulation = ft_time(miliseconde);
    set_bool(&data->table_mutex, &data->all_thread_ready, 1);
    i = 0;
    while (i < data->philo_numbers)
    {
        safe_thread(&data->philos[i].thread_id, NULL, NULL, join);
        i++;
    }
}