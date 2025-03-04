/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 21:00:47 by ababdoul          #+#    #+#             */
/*   Updated: 2025/03/04 04:05:05 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo/philosopher.h"

// void *my_func(void *arg)
// {
//     sleep(1);
//     printf("abdou is here\n");
//     return NULL;
// }
// int main()
// {
//     pthread_t id;
    
//     printf("before thread\n");
//     pthread_create(&id, NULL, my_func, NULL);
//     pthread_join(id, NULL);
//     printf("after thread\n");
// }

void *function(void *arg)
{
    int i = *(int *)arg;
    printf("thread detected ****  : %d\n", i);
    i++;    
    sleep(2);
    printf("end of thread !!\n");
}
int main(int ac , char **av)
{
    pthread_t id1, id2, id3;
    int i1 = 0, i2 = 1, i3 = 2;
    // printf("first thread id : %d\n",pthread_create(&id1, NULL, &function, NULL));
    if (pthread_create(&id1, NULL, &function, &id1) != 0)
        return (1);
    // printf("seconde thread id : %d\n",pthread_create(&id2, NULL, &function, NULL));
    if (pthread_create(&id2, NULL, &function, &id2) != 0)
        return  (2);
    // printf("third thread id : %d\n",pthread_create(&id3, NULL, &function, NULL));
    if (pthread_create(&id3, NULL, &function, &id3))
        return (3);
    pthread_join(id1, NULL);
    pthread_join(id2, NULL);
    pthread_join(id3, NULL);


    printf("%d\n", 2 % 5);
}