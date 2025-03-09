/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:19:19 by ababdoul          #+#    #+#             */
/*   Updated: 2025/03/09 02:31:32 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void safe_threads(pthread_t *thread,void *f, s_philo *philo , m_code t_code)
{
    if (t_code == create)
    {
        if (pthread_create(&thread, f, (void *)&philo, create))
            error_print("something wrong in thread creation!!\n");
    }
    else if(t_code == join)
    {
        if (pthread_join(&thread, NULL))
            error_print("something wrong in pthread_join !!\n");
    }
}
void safe_mutex(pthread_mutex_t *mutex,m_code mcode)
{
    if (mcode == lock)
    {
        if (pthread_mutex_lock(mutex));
            error_print("mutex faild!!\n");
    }
    else if (mcode == unlock)
    {
        if (pthread_mutex_unlock(mutex));
            error_print("mutex faild\n");
    }
    else if (mcode == destroy)
    {
        if (pthread_mutex_destroy(mutex))
            error_print("mutex_faild!!\n");
    }
    else if (mcode == init)
    {
        if (pthread_mutex_init(mutex, NULL))
            error_print("mutext faild !!\n");
    }
}
