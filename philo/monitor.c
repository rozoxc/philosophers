/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:12:49 by ababdoul          #+#    #+#             */
/*   Updated: 2025/05/13 01:30:14 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static int	check_philo_death(s_philo *philo, s_data *data, int i)
{
	(void)philo;
	if (data->death)
		return (1);
	if (get_time() - data->start_time > data->time_to_die)
	{
		data->death = 1;
		printf("philo[%d] on %ld ms : is died\n", i , get_time() - data->start_time);
		return (1);
	}
	return (0);
}


void	*monitor_routine(void *arg)
{
	s_philo	*philo;
	s_data	*data;

	philo = (s_philo *)arg;
	data = philo->data;
	int i = 0;
	while (1)
	{
		safe_mutex(&data->dead_mutex, LOCK);
		if (data->death == 1)
		{
			safe_mutex(&data->dead_mutex, UNLOCK);
			break;
		}
		if (check_philo_death(philo, data,i))
		{
			safe_mutex(&data->dead_mutex, UNLOCK);
			break ;
		}
		safe_mutex(&data->dead_mutex, UNLOCK);
		i++;
		if (i == data->philosopher_count)
			i = 0;
	}
	return (NULL);
}


