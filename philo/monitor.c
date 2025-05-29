/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:12:49 by ababdoul          #+#    #+#             */
/*   Updated: 2025/05/29 18:40:41 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	check_philo_death(t_philo *philo, t_data *data)
{
	if (get_time() - philo->last_meal_time > data->time_to_die)
	{
		data->death = 1;
		printf("%d %d died\n", get_time() - data->start_time, philo->id);
		return (1);
	}
	return (0);
}

void	*monitor_routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	while (1)
	{
		safe_mutex(&data->dead_mutex, LOCK);
		if (data->death == 1)
		{
			safe_mutex(&data->dead_mutex, UNLOCK);
			break ;
		}
		if (check_philo_death(philo, data))
		{
			safe_mutex(&data->dead_mutex, UNLOCK);
			return (NULL);
		}
		if (data->number_of_meals == philo->meals_eaten)
			return (safe_mutex(&data->dead_mutex, UNLOCK), NULL);
		safe_mutex(&data->dead_mutex, UNLOCK);
	}
	return (NULL);
}
