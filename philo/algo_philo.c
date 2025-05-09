/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:58:01 by ababdoul          #+#    #+#             */
/*   Updated: 2025/05/09 03:19:23 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	sleep_and_think(s_philo *philo)
{
	s_data	*data;

	data = philo->data;
	print_status(philo, "is sleeping");
	ft_sleep(data->time_to_sleep);
	safe_mutex(&data->monitor_mutex, LOCK);
	if (data->death)
	{
		safe_mutex(&data->monitor_mutex, UNLOCK);
		return ;
	}
	safe_mutex(&data->monitor_mutex, UNLOCK);
	print_status(philo, "is thinking");
	if (philo->id % 2 == 0 && data->philosopher_count > 2)
		ft_sleep(10);
}

void	eat(s_philo *philo)
{
	s_data	*data;

	data = philo->data;
	print_status(philo, "is eating");
	safe_mutex(&data->monitor_mutex, LOCK);
	philo->last_meal_time = get_time();
	philo->meals_eaten++;
	safe_mutex(&data->monitor_mutex, UNLOCK);
	ft_sleep(data->time_to_eat);
}

void	take_fork(s_data *data, s_philo *philo)
{
	(void)data;
	safe_mutex(philo->right_fork, LOCK);
	print_status(philo, "taken right fork");
	safe_mutex(philo->left_fork, LOCK);
	print_status(philo, "taken left fork");
}

void	put_forks(s_philo *philos)
{
	safe_mutex(philos->right_fork, UNLOCK);
	print_status(philos, "put right fork");
	safe_mutex(philos->left_fork, UNLOCK);
	print_status(philos, "put left fork");
}
