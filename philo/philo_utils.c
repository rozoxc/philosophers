/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 23:55:03 by ababdoul          #+#    #+#             */
/*   Updated: 2025/05/13 01:42:25 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int print_status(s_philo *philo, char *message)
{
    long time_stamp;
    s_data *data;
    
    data = philo->data;
    safe_mutex(&data->dead_mutex, LOCK);
    
    if (!data->death)
    {
		time_stamp = get_time() - data->start_time;
		printf("%ld ms : philo[%d] %s\n", time_stamp, philo->id, message);
		safe_mutex(&data->dead_mutex, UNLOCK);
       	return (0);
    }
    safe_mutex(&data->dead_mutex, UNLOCK);
	return (1);

}

void	cleanup(s_data *data, s_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->philosopher_count)
	{
		safe_mutex(&data->forks[i], DESTROY);
		i++;
	}
	safe_mutex(&data->dead_mutex, DESTROY);
	safe_mutex(&data->monitor_mutex, DESTROY);
	safe_mutex(&data->write_mutex, DESTROY);
	free(data->forks);
	if (philo)
		free(philo);
}
