/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:12:49 by ababdoul          #+#    #+#             */
/*   Updated: 2025/05/09 03:38:55 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static int	check_philo_death(s_philo *philo, s_data *data, int i)
{
	if ((get_time() - philo[i].last_meal_time) > data->time_to_die)
	{
		safe_mutex(&data->dead_mutex, LOCK);
		data->death = 1;
		safe_mutex(&data->dead_mutex, UNLOCK);
		print_status(&philo[i], "died");
		safe_mutex(&data->monitor_mutex, UNLOCK);
		return (1);
	}
	return (0);
}

static int	philosopher_meal_check(s_philo *philo, s_data *data)
{
	int	i;
	int	done;

	i = 0;
	done = 0;
	while (i < data->philosopher_count)
	{
		if (check_philo_death(philo, data, i))
			return (-1);
		if (data->number_of_meals > 0
			&& philo[i].meals_eaten >= data->number_of_meals)
			done++;
		i++;
	}
	return (done);
}

static int	check_all_philosophers_done(s_data *data, int done)
{
	if (data->number_of_meals > 0 && done == data->philosopher_count)
	{
		safe_mutex(&data->dead_mutex, LOCK);
		data->death = 1;
		safe_mutex(&data->dead_mutex, UNLOCK);
		safe_mutex(&data->monitor_mutex, UNLOCK);
		printf("All philosophers ate enough meals!\n");
		return (1);
	}
	return (0);
}

void	*monitor_routine(void *arg)
{
	s_philo	*philo;
	s_data	*data;
	int		done;

	philo = (s_philo *)arg;
	data = philo->data;
	while (1)
	{
		done = 0;
		usleep(1000);
		safe_mutex(&data->monitor_mutex, LOCK);
		safe_mutex(&data->dead_mutex, LOCK);
		if (data->death)
		{
			safe_mutex(&data->dead_mutex, UNLOCK);
			safe_mutex(&data->monitor_mutex, UNLOCK);
			break ;
		}
		safe_mutex(&data->dead_mutex, UNLOCK);
		done = philosopher_meal_check(philo, data);
		if (done == -1)
			return (NULL);
		if (check_all_philosophers_done(data, done))
			return (NULL);
		safe_mutex(&data->monitor_mutex, UNLOCK);
	}
	return (NULL);
}


