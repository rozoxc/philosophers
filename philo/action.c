/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 21:56:49 by ababdoul          #+#    #+#             */
/*   Updated: 2025/02/26 00:09:58 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void *philosopher_routine(void *arg)
{
    
    s_data *data;
    s_philo *philo;

    philo = (s_philo *)arg;
    printf("lslsl\n");
    printf("heere!!\n");
    // data = philo->data;
    printf("hallo\n");
    if (data->philosopher_count == 1)
    {
        printf("hallo\n");
        print_status(philo, "has taken a fork");
        ft_sleep(data->time_to_die);
        print_status(philo, "died");
        return (NULL);
    }
    return (NULL);
}
int     start_simulation(s_philo *philos, s_data *data)
{
    int i;

    i = 0;
    while (i < data->philosopher_count)
    {
        if (pthread_create(&philos->thread, NULL, philosopher_routine, NULL))
            return (0);
        usleep(100);   
        i++;
    }
    return (1);
}