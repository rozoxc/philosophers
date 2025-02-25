/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:47:02 by ababdoul          #+#    #+#             */
/*   Updated: 2025/02/25 01:20:10 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int check_argument(int i)
{
    if (i == 5)
        return (1);
    return (0);
}

void *message()
{
    printf("thread detected ****\n");
    return NULL;
}
int creat_threads(int number_of_philo)
{
    int i;
    pthread_t pid;

    i = 0;
    while (i < number_of_philo)
    {
        if (pthread_create(&pid, NULL, message, NULL))
            return (0);
        pthread_join(pid, NULL);
        i++;
    }
    return (1);
}
int main(int ac, char **av)
{
    int number_of_philo;
    s_data data;

    if (!check_argument(ac))
    {
        printf("invalid number of argument!!\n");
        printf("Usage: ./philo 12 1000 1000 120\n");
        return (0);
    }
    number_of_philo = ft_atoi(av[1]);
    data.time_to_die = ft_atoi(av[2]);
    data.time_to_eat = ft_atoi(av[3]);
    data.time_to_sleep = ft_atoi(av[4]);
    creat_threads(number_of_philo);
    printf("there is philosophers : %d\n", number_of_philo);
    printf("numbers of forks : %d\n", number_of_philo);
    printf("time to die : %d\n",data.time_to_die);
    printf("numbers of forks : %d\n", number_of_philo);
}
