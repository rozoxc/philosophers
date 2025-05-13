/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:03:45 by ababdoul          #+#    #+#             */
/*   Updated: 2025/05/13 03:50:40 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

size_t    get_time()
{
    struct timeval tv;

    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
void    ft_sleep(size_t miliseconde)
{
    size_t    start;
    size_t    current;

    start = get_time();
    while (1)
    {
        current = get_time();
        if (current - start >= miliseconde)
            break;
        usleep(100);
    }
}