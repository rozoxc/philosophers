/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:58:01 by ababdoul          #+#    #+#             */
/*   Updated: 2025/05/29 22:52:20 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	sleep_and_think(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	if (print_status(philo, "is sleeping"))
		return (1);
	ft_sleep(data->time_to_sleep, data);
	if (print_status(philo, "is thinking"))
		return (1);
	return (0);
}

int	eat(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	if (print_status(philo, "is eating"))
		return (safe_mutex(philo->right_fork, UNLOCK),
			safe_mutex(philo->left_fork, UNLOCK), 1);
	safe_mutex(&data->dead_mutex, LOCK);
	philo->last_meal_time = get_time();
	philo->meals_eaten++;
	data->is_eating = 1;
	safe_mutex(&data->dead_mutex, UNLOCK);
	ft_sleep(data->time_to_eat, data);
	return (0);
}

int	take_fork(t_data *data, t_philo *philo)
{
	(void)data;
	safe_mutex(&data->dead_mutex, LOCK);
	if (data->death)
		return (safe_mutex(&data->dead_mutex, UNLOCK), 1);
	safe_mutex(&data->dead_mutex, UNLOCK);
	safe_mutex(philo->right_fork, LOCK);
	if (print_status(philo, "has taken a fork"))
		return (safe_mutex(philo->right_fork, UNLOCK), 1);
	safe_mutex(philo->left_fork, LOCK);
	if (print_status(philo, "has taken a fork"))
		return (safe_mutex(philo->right_fork, UNLOCK),
			safe_mutex(philo->left_fork, UNLOCK), 1);
	return (0);
}

int	put_forks(t_philo *philos)
{
	safe_mutex(philos->right_fork, UNLOCK);
	safe_mutex(philos->left_fork, UNLOCK);
	safe_mutex(&philos->data->dead_mutex, LOCK);
	if (philos->meals_eaten == philos->data->number_of_meals)
		return (safe_mutex(&philos->data->dead_mutex, UNLOCK), 1);
	safe_mutex(&philos->data->dead_mutex, UNLOCK);
	return (0);
}
