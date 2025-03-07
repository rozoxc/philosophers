/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 05:13:56 by ababdoul          #+#    #+#             */
/*   Updated: 2025/03/07 05:54:24 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long ft_time(s_time time_code)
{
    struct timeval tv;

    if (gettimeofday(&tv, NULL))
        error_print("gettimeofday faild !!\n");
    if (time_code == seconde)
        return (tv.tv_sec + (tv.tv_usec / 1e6));
    else if (time_code == miliseconde)
        return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
    else if (time_code == microseconde)
        return ((tv.tv_sec * 1e6) + (tv.tv_usec));
    else
        error_print("time_code not found !!!\n");
    return (11111);
}
void ft_usleep(long usec, s_data *data)
{
    long start;
    long rem;
    long elapsed;

    start = ft_time(microseconde);
    while (ft_time(microseconde) - start < usec)
    {
        if (simulation_done(data))
            break ;
        elapsed = ft_time(microseconde) - start;
        rem = usec - elapsed;
        if (rem > 1000)
            usleep(usec / 2);
        else
        {
            while (ft_time(microseconde) - start < usec);
        }
    }
}
void wait_threads(s_data *data)
{
    while (!get_bool(&data->table_mutex, &data->all_thread_ready));
}
