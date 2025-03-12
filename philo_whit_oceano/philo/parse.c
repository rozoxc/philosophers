/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 04:44:03 by ababdoul          #+#    #+#             */
/*   Updated: 2025/03/10 23:23:29 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void parse_input(s_data *data , char **av)
{
    if (!is_digit(av[1]))
        error_print("number of philosopher is not digit!!\n");
    data->philo_numbers = ft_atoi(av[1]);
    data->time_to_die = ft_atoi(av[2]) * 1000;
    data->timt_to_eat =  ft_atoi(av[3]) * 1000;
    data->time_to_sleep = ft_atoi(av[4]) * 1000;
    if (data->time_to_die < 6000 || data->timt_to_eat < 6000 ||
        data->time_to_sleep < 6000)
        error_print("timestamp id too loww!!\n");
    if (av[5])
        data->number_of_meals = ft_atoi(av[5]);
    else
        data->number_of_meals = -1;
            
}