/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 04:21:20 by ababdoul          #+#    #+#             */
/*   Updated: 2025/03/12 03:50:36 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_argument(int ac)
{
    if (ac == 5 || ac == 6)
        return (1);
    return (0);
}
int main(int ac, char **av)
{
    s_data data;

    if (!check_argument(ac))
        error_print("invalid number of argument !!\n");
    parse_input(&data , av); // done
    init_data(&data); // done
    start_simulation(&data); // still
    // clean(&data);
}