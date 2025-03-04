/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:10:16 by ababdoul          #+#    #+#             */
/*   Updated: 2025/03/04 03:54:44 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int init_data(s_data *data, int ac, char **av)
{

    data->philosopher_count = ft_atoi(av[1]);
    data->time_to_die = ft_atoi(av[2]);
    data->time_to_eat = ft_atoi(av[3]);
    data->time_to_sleep = ft_atoi(av[4]);

    if (ac == 6)
        data->number_of_meals = ft_atoi(av[5]);
    else
        data->number_of_meals = -1;
    data->death = 0;
    data->all_ate = 0;
    data->start_time = get_time();

    if (pthread_mutex_init(&data->write_mutex, NULL))
        return (0);
    if(pthread_mutex_init(&data->dead_mutex, NULL))
        return (0);
    return (1);
}
int init_forks(s_data *data)
{
    int i;

    data = malloc(sizeof(s_data) * data->philosopher_count);
    if (!data)
        return (0);
    i = 0;
    while (i < data->philosopher_count)
    {
        if (pthread_mutex_init(data->forks, NULL) != 0)
            return (0);
        i++;
    }
    return (1);
}

int init_philo(s_philo **philo, s_data *data)
{
    int i;
    int j;

    *philo = malloc(sizeof(s_philo) * data->philosopher_count);
    if (!*philo)
        return (0);
    i = 0;
    j = 1;
    while (i < data->philosopher_count)
    {
        (*philo)[i].id = j;
        (*philo)[i].meals_eaten = 0;
        (*philo)[i].last_meal_time =  data->start_time;
        (*philo)[i].left_fork = data->forks[i];
        (*philo)[i].right_fork = data->forks[(i + 1) % data->philosopher_count];
        (*philo)[i].data = data;
        printf(" philo number : %d\n", (*philo)[i].id );
        i++;
        j++;
    }
    return (1);
}
