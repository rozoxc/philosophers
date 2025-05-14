/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 21:56:49 by ababdoul          #+#    #+#             */
/*   Updated: 2025/05/14 03:05:38 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*philosopher_routine(void *arg)
{
	s_philo	*philo;
	s_data	*data;

	philo = (s_philo *)arg;
	data = philo->data;
	if (data->philosopher_count == 1)
	{
		safe_mutex(philo->right_fork, LOCK);
		print_status(philo, "has taken a fork");
		ft_sleep(data->time_to_die);
		print_status(philo, "died");
		data->death = 1;
		safe_mutex(philo->right_fork, UNLOCK);
		return (NULL);
	}
	if (philo->id % 2 == 0)
		ft_sleep(data->time_to_eat / 2);
	while (1)
	{
		if (take_fork(data, philo))
			break;
		if (eat(philo))
			break;
		if (put_forks(philo))
			break;
		if (sleep_and_think(philo))
			break;
	}
	return (NULL);
}

int	start_simulation(s_philo *philos, s_data *data)
{
	int	i;

	i = 0;
	data->start_time = get_time();
	while (i < data->philosopher_count)
	{
		// philos[i].last_meal_time = get_time();
		if (!safe_thread(&philos[i].thread, CREAT, philosopher_routine, &philos[i]))
		{
			safe_mutex(&data->dead_mutex, LOCK);
			data->death = 1;
			safe_mutex(&data->dead_mutex, UNLOCK);
			return (0);
		}
		i++;
	}
	if (!safe_thread(&data->monitor_thread, CREAT, monitor_routine, philos))
	{
		safe_mutex(&data->dead_mutex, LOCK);
		data->death = 1;
		safe_mutex(&data->dead_mutex, UNLOCK);
		return (0);
	}
	i = 0;
	while (i < data->philosopher_count)
	{
		if (!safe_thread(&philos[i].thread, JOIN, NULL, NULL))
			return (0);
		i++;
	}
	if (!safe_thread(&data->monitor_thread, JOIN, NULL, NULL))
		return (0);
	return (1);
}
