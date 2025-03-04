/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 04:46:00 by ababdoul          #+#    #+#             */
/*   Updated: 2025/03/04 05:36:32 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long ft_atoi(char *str)
{
    int i;
    long num;
    int signe;

    num = 0;
    signe = 1;
    i = 0;

    while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            error_print("negative value are forbidden !!\n");
        i++;
    }
    while (str[i] != '\0' || (str[i] >= '0' && str[i] <= '9'))
    {
        num *= 10;
        num += str[i] - '0';
        i++;
    }
    return (num * signe);
}

