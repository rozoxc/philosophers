/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:03:45 by ababdoul          #+#    #+#             */
/*   Updated: 2025/02/25 23:31:31 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

long    get_time()
{
    struct timeval tv;

    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
void    ft_sleep(long miliseconde)
{
    long    start;
    long    current;

    start = get_time();
    while (1)
    {
        current = get_time();
        if (current - start >= miliseconde)
            break;
        usleep(100);
    }
}