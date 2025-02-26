/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:47:02 by ababdoul          #+#    #+#             */
/*   Updated: 2025/02/25 22:09:37 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int check_argument(int i)
{
    if (i == 5 || i == 6)
        return (1);
    return (0);
}

void *message()
{
    printf("thread detected ****\n");
    return NULL;
}
// int creat_threads(int number_of_philo)
// {
//     int i;
//     pthread_t pid;

//     i = 0;
//     while (i < number_of_philo)
//     {
//         if (pthread_create(&pid, NULL, message, NULL))
//             return (0);
//         pthread_join(pid, NULL);
//         i++;
//     }
//     return (1);
// }
int main(int ac, char **av)
{
    s_data data;
    s_philo *philo;
    // data = NULL;
    if (!check_argument(ac))
    {
        printf("invalid number of argument!!\n");
        printf("Usage: ./philo 12 1000 1000 120\n");
        return (0);
    }
    if (!init_data(&data, ac, av))
    {
        printf("error of inizialize data !!!\n");
        return (0);
    }
    if (!init_philo(&philo, &data))
    {
        printf("faild to inizialize philosophers !!\n");
        return (0);
    }
    if (!start_simulation(philo, &data))
    {
        printf("start simulation faild !!");
        return (0);
    }
    
}
