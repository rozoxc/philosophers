/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:10:16 by ababdoul          #+#    #+#             */
/*   Updated: 2025/05/27 20:17:25 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	check_signe(t_data *data)
{
	if (data->philosopher_count <= 0 || data->philosopher_count > 200)
		return (1);
	else if (data ->time_to_die < 60)
		return (1);
	else if (data->time_to_eat < 60)
		return (1);
	else if (data->time_to_sleep < 60)
		return (1);
	else if (data->number_of_meals <= 0 && data->number_of_meals != -1)
		return (1);
	return (0);
}

int	init_data(t_data *data, int ac, char **av)
{
	data->philosopher_count = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->number_of_meals = ft_atoi(av[5]);
	else
		data->number_of_meals = -1;
	if (check_signe(data) == 1)
		return (0);
	data->death = 0;
	data->all_ate = 0;
	data->start_time = get_time();
	data->forks = NULL;
	if (!safe_mutex(&data->dead_mutex, INIT))
		return (0);
	if (!safe_mutex(&data->monitor_mutex, INIT))
	{
		safe_mutex(&data->dead_mutex, DESTROY);
		return (0);
	}
	return (1);
}

int	init_forks(t_data *data)
{
	int	i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->philosopher_count);
	if (!data->forks)
		return (0);
	i = 0;
	while (i < data->philosopher_count)
	{
		if (!safe_mutex(&data->forks[i], INIT))
		{
			while (--i >= 0)
				safe_mutex(&data->forks[i], DESTROY);
			free(data->forks);
			return (0);
		}
		i++;
	}
	return (1);
}

int	init_philo(t_philo **philo, t_data *data)
{
	int	i;
	int	j;

	*philo = malloc(sizeof(t_philo) * data->philosopher_count);
	if (!*philo)
		return (0);
	i = 0;
	j = 1;
	while (i < data->philosopher_count)
	{
		(*philo)[i].id = j;
		(*philo)[i].meals_eaten = 0;
		(*philo)[i].last_meal_time = data->start_time;
		(*philo)[i].left_fork = &data->forks[i];
		(*philo)[i].right_fork = &data->forks[(i + 1)
			% data->philosopher_count];
		(*philo)[i].data = data;
		i++;
		j++;
	}
	return (1);
}
