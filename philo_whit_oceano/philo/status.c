/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 05:55:13 by ababdoul          #+#    #+#             */
/*   Updated: 2025/03/07 06:01:45 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
void print_status(s_status status, s_philo *philo)
{
        safe_mutex(&philo->data->write_mutex, lock);
        
}