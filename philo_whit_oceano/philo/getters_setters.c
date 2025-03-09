/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_setters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 04:14:01 by ababdoul          #+#    #+#             */
/*   Updated: 2025/03/09 03:18:15 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void set_bool(pthread_mutex_t *mutex, bool *dest, bool value)
{
    safe_mutex(mutex, lock);
    *dest = value;
    safe_mutex(mutex, unlock);
}

bool get_bool(pthread_mutex_t *mutex, bool *value)
{
    bool res;

    safe_mutex(mutex, lock);
    res = *value;
    safe_mutex(mutex, unlock);
    return (res);
}

void set_long(pthread_mutex_t *mutex, long *dest, long value)
{
    safe_mutex(mutex, lock);
    *dest = value;
    safe_mutex(mutex, unlock);
}

long get_long(pthread_mutex_t *mutex, long *value)
{
    long res;
    safe_mutex(mutex, lock);
    res = *value;
    safe_mutex(mutex, unlock);
    return (res);
}

bool  simulation_done(s_data *data)
{
    return (get_bool(&data->table_mutex, &data->end_of_simulation));
}