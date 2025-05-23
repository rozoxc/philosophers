/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 04:26:41 by ababdoul          #+#    #+#             */
/*   Updated: 2025/05/23 04:34:49 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int		parse_input(t_data *data)
{
    if (data->philosopher_count == 0)
        return (0);
    else if (data->number_of_meals == 0)
        return (0);
    else if (data->time_to_die == 0)
        return (0);
    else if (data->time_to_eat == 0)
        return (0);
    else if (data->time_to_sleep == 0)
        return (0);
    return (1);
}
