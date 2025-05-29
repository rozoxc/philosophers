/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:03:45 by ababdoul          #+#    #+#             */
/*   Updated: 2025/05/27 20:23:19 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_sleep(int miliseconde, t_data *data)
{
	int	start;
	int	current;

	start = get_time();
	while (1)
	{
		safe_mutex(&data->dead_mutex, LOCK);
		if (data->death == 1)
		{
			safe_mutex(&data->dead_mutex, UNLOCK);
			break ;
		}
		safe_mutex(&data->dead_mutex, UNLOCK);
		current = get_time();
		if (current - start >= miliseconde)
			break ;
		usleep(100);
	}
}
