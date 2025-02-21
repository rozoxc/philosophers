/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:47:02 by ababdoul          #+#    #+#             */
/*   Updated: 2025/02/21 18:14:15 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
int check_argument(int i)
{
    if (i == 5)
        return (1);
    return (0);
}
int main(int ac, char **av)
{
    (void)av;
    if (!check_argument(ac))
    {
        printf("invalid number of argumen!!");
        return (0);
    }
}