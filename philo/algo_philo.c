/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:58:01 by ababdoul          #+#    #+#             */
/*   Updated: 2025/03/16 23:36:49 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void take_fork(s_data *data, s_philo *philo)
{
    if (data->philosopher_count % 2 == 0)
    {
        pthread_mutex_lock(&philo->right_fork);
        print_status(philo, "taken right fork");
        pthread_mutex_lock(&philo->left_fork);
        print_status(philo, "taken left fork");   
    }
    else
    {
        pthread_mutex_lock(&philo->left_fork);
        print_status(philo, "taken left fork");
        pthread_mutex_lock(&philo->right_fork);
        print_status(philo, "taken right fork");
    }
}
void put_forks(s_philo *philos)
{
    pthread_mutex_unlock(&philos->right_fork);
    pthread_mutex_unlock(&philos->left_fork);
}
void    algo_philo(s_philo *philo, s_data *data)
{
    if (data->philosopher_count % 2 == 0)
        ft_sleep(data->time_to_eat /  2);
    while (1)
    { 
        if (pthread_mutex_lock(&data->dead_mutex))
            printf("mutex lock faild\n");
        if (data->death || philo->meals_eaten >= data->number_of_meals)
        {
            pthread_mutex_unlock(&data->dead_mutex);
            break;
        }
        pthread_mutex_unlock(&data->dead_mutex);
        take_fork(data, philo);
        print_status(philo, "is eating");
        if (pthread_mutex_lock(&data->dead_mutex))
            printf("mutex faild\n");;
        philo->last_meal_time = get_time();
        philo->meals_eaten++;
        pthread_mutex_unlock(&data->dead_mutex);
        ft_sleep(data->time_to_eat);
        put_forks(philo);
        print_status(philo, "is sleeping");
        ft_sleep(data->time_to_sleep);
        print_status(philo, "is thinking");
    }
}
