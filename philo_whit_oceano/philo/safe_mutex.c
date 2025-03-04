/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:19:19 by ababdoul          #+#    #+#             */
/*   Updated: 2025/03/04 18:26:49 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void safe_mutext(pthread_mutex_t *mutex,m_code mcode)
{
    if (mcode == lock)
        pthread_mutex_lock(mutex);
    else if (mcode == unlock)
        pthread_mutex_unlock(mutex);
    else if (mcode == destroy)
        pthread_mutex_destroy(mutex);
    else if (mcode == init)
        pthread_mutex_init(mutex, NULL);
}