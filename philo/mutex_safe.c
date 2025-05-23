/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_safe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 01:29:58 by ababdoul          #+#    #+#             */
/*   Updated: 2025/05/23 04:10:18 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	safe_mutex(pthread_mutex_t *mutex, t_type_mutex type)
{
	if (type == INIT)
	{
		if (pthread_mutex_init(mutex, NULL))
		{
			printf("mutex init faild\n");
			return (0);
		}
	}
	else if (type == LOCK)
	{
		if (pthread_mutex_lock(mutex))
		{
			printf("mutex lock faild\n");
			return (0);
		}
	}
	else if (type == UNLOCK)
	{
		if (pthread_mutex_unlock(mutex))
		{
			printf("mutex unlock faild\n");
			return (0);
		}
	}
	return (1);
}

int	safe_thread(pthread_t *thread, t_type_thread type,
	void *(*f)(void *), t_philo *philos)
{
	if (type == CREAT)
	{
		if (pthread_create(thread, NULL, f, philos) != 0)
			return (0);
	}
	else if (type == JOIN)
	{
		if (pthread_join(*thread, NULL) != 0)
			return (0);
	}
	return (1);
}
