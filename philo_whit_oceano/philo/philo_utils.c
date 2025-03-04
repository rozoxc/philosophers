/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 04:32:16 by ababdoul          #+#    #+#             */
/*   Updated: 2025/03/04 05:37:50 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void error_print(char *message)
{
    printf("%s", message);
    exit(1);
}
int is_digit(char *str)
{
    int i;

    i = 0;
    if (str[i] == '-' || str[i] == '+')
            i++;
    while (str[i] != '\0')
    {
        if (str[i] <= '0' || str[i] >= '9')
            return (0);
        i++;
    }
    return (1);
}