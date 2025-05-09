/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:47:02 by ababdoul          #+#    #+#             */
/*   Updated: 2025/05/09 02:02:00 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	check_argument(int i)
{
	if (i == 5 || i == 6)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	s_data	data;
	s_philo	*philo;

	if (!check_argument(ac))
	{
		printf("invalid number of argument!!\n");
		printf("Usage: ./philo 12 1000 1000 120\n");
		return (0);
	}
	if (!init_data(&data, ac, av))
		return (printf("error of inizialize data!!!\n"), 0);
	if (!init_forks(&data))
	{
		printf("faild to initialize forks!! \n");
		return (0);
	}
	if (!init_philo(&philo, &data))
	{
		printf("faild to inizialize philosophers !!\n");
		return (cleanup(&data, NULL), 0);
	}
	if (!start_simulation(philo, &data))
		return (printf("start simulation faild !!"), cleanup(&data, NULL), 0);
	cleanup(&data, NULL);
}
