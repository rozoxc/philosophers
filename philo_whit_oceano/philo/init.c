/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 05:45:01 by ababdoul          #+#    #+#             */
/*   Updated: 2025/03/07 05:57:05 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void init_forks(s_philo *philo,s_forks *forks, int i)
{

    philo->first_fork = &forks[(i + 1) % philo->data->philo_numbers];
    philo->second_fork = &forks[i];
    if (philo->id % 2 == 0)
    {
        philo->first_fork = &forks[i];   
        philo->second_fork = &forks[(i + 1) % philo->data->philo_numbers];
    }
}
void philo_init(s_data *data)
{
    int i;
    int j;
    s_philo *philo;
    
    j = 1;
    i = 0;
    while (data->philo_numbers)
    {
        philo = &data->philos[i];
        philo->id = j;
        philo->full = 0;
        philo->meal_eaten = 0;
        philo->data = data;
        init_forks(philo, data->forks, i);
        i++;
    }
}
void init_data(s_data *data)
{
    int i;

    i = 0;
    data->end_of_simulation = 0;
    data->philos = malloc(sizeof(s_data) * data->philo_numbers);
    if (!data->philos)
        return ;
    data->forks = malloc(sizeof(s_data) * data->philo_numbers);
    safe_mutex(&data->table_mutex, init);
    safe_mutex(&data->write_mutex, init);
    if (!data->forks)
        return ;
    while (i < data->philo_numbers) 
    {
        safe_mutex(&data->forks[i].fork, init);
        data->forks[i].id_fork = i;
        i++;
    }
    philo_init(data);
}
