/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 23:55:03 by ababdoul          #+#    #+#             */
/*   Updated: 2025/02/28 01:32:38 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

void print_status(s_philo *philo, char *message)
{
	long time_stamp;
	s_data *data;

	data = philo->data;
	pthread_mutex_lock(&data->dead_mutex);
	if (!data->death || !ft_strcmp(message, "died"))
	{
		time_stamp = get_time() - data->start_time;
		pthread_mutex_lock(&data->write_mutex);
		printf("%ld ms :  philo[%d] %s\n", time_stamp, philo->id, message);
		pthread_mutex_unlock(&data->write_mutex);
	}
	pthread_mutex_unlock(&data->dead_mutex);
}