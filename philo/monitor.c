/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:12:49 by ababdoul          #+#    #+#             */
/*   Updated: 2025/05/23 04:15:14 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	check_philo_death(t_philo *philo, t_data *data, int i)
{
	(void)philo;
	if (data->death)
		return (1);
	if (get_time() - philo->last_meal_time > data->time_to_die)
	{
		data->death = 1;
		printf("%ld ms : philo[%d] is died\n", get_time() - data->start_time, i);
		return (1);
	}
	return (0);
}

void	*monitor_routine(void *arg)
{
	int	i;
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	i = 0;
	while (1)
	{
		safe_mutex(&data->dead_mutex, LOCK);
		if (data->death == 1)
		{
			safe_mutex(&data->dead_mutex, UNLOCK);
			break ;
		}
		if (check_philo_death(philo, data, i))
		{
			safe_mutex(&data->dead_mutex, UNLOCK);
			break ;
		}
		i++;
		if (i == data->philosopher_count)
			i = 0;
		if (data->number_of_meals == philo->meals_eaten)
			return (safe_mutex(&data->dead_mutex, UNLOCK), NULL);
		safe_mutex(&data->dead_mutex, UNLOCK);
	}
	return (NULL);
}
