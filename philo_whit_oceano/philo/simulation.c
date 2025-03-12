/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 03:46:43 by ababdoul          #+#    #+#             */
/*   Updated: 2025/03/12 04:58:04 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *philo_routine(void *data)
{
    s_philo *philo;
    philo = (s_philo *)data;

    // Wait until all threads are ready
    while (!get_bool(&philo->data->table_mutex, &philo->data->all_thread_ready))
        usleep(100);

    // If the philosopher is the only one, handle the single philosopher case
    if (philo->data->philo_numbers == 1)
    {
        safe_mutex(&philo->data->forks[philo->id - 1].fork, lock);
        printf("%ld %d has taken a fork\n", ft_time(miliseconde) - philo->data->start_simulation, philo->id);
        ft_usleep(philo->data->time_to_die, philo->data);
        safe_mutex(&philo->data->forks[philo->id - 1].fork, unlock);
        return NULL;
    }

    // Main loop for the philosopher's lifecycle
    while (!simulation_done(philo->data))
    {
        // Thinking
        printf("%ld %d is thinking\n", ft_time(miliseconde) - philo->data->start_simulation, philo->id);

        // Take first fork
        safe_mutex(&philo->first_fork->fork, lock);
        printf("%ld %d has taken a fork\n", ft_time(miliseconde) - philo->data->start_simulation, philo->id);

        // Take second fork
        safe_mutex(&philo->second_fork->fork, lock);
        printf("%ld %d has taken a fork\n", ft_time(miliseconde) - philo->data->start_simulation, philo->id);

        // Eating
        set_long(&philo->data->table_mutex, &philo->last_meal_time, ft_time(miliseconde));
        printf("%ld %d is eating\n", ft_time(miliseconde) - philo->data->start_simulation, philo->id);
        ft_usleep(philo->data->timt_to_eat, philo->data);
        philo->meal_eaten++;

        // Release forks
        safe_mutex(&philo->first_fork->fork, unlock);
        safe_mutex(&philo->second_fork->fork, unlock);

        // Check if the philosopher has eaten enough meals
        if (philo->data->number_of_meals > 0 && philo->meal_eaten >= philo->data->number_of_meals)
        {
            set_bool(&philo->data->table_mutex, &philo->full, true);
            break;
        }

        // Sleeping
        printf("%ld %d is sleeping\n", ft_time(miliseconde) - philo->data->start_simulation, philo->id);
        ft_usleep(philo->data->time_to_sleep, philo->data);
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
    else
        while (i < data->philo_numbers)
        {
            safe_threads(&data->philos[i].thread_id ,philo_routine, &data->philos[i], create);
            i++;
        }
    data->start_simulation = ft_time(miliseconde);
    set_bool(&data->table_mutex, &data->all_thread_ready, 1);
    i = 0;
    while (i < data->philo_numbers)
    {
        safe_threads(&data->philos[i].thread_id, NULL, NULL, join);
        i++;
    }
}
