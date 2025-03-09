/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 05:55:13 by ababdoul          #+#    #+#             */
/*   Updated: 2025/03/08 00:35:53 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
void print_status(s_status status, s_philo *philo, bool debug)
{
        long elapsed;

        elapsed = ft_time(miliseconde) - philo->data->start_simulation;
        if (philo->full)
                return ;
        safe_mutex(&philo->data->write_mutex, lock);
        if (debug == 1)
                print_status_debug(status, philo, elapsed);
        else
        {
                if (status == eating)
                        printf("philo[%d] is eating\n", philo->id);
                else if (status == sleeping)
                        printf("philo[%d] is sleeping\n", philo->id);
                else if (status == thinking)
                        printf("philo[%d] is thinking\n", philo->id);
                else if (status == take_first_fork)
                        printf("philo[%d] take first fork\n", philo->id);
                else if (status == take_seconde_fork)
                        printf("philo[%d] take seconde fork \n", philo->id);
        }
        safe_mutex(&philo->data->write_mutex, unlock);
}