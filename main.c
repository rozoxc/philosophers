/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 21:00:47 by ababdoul          #+#    #+#             */
/*   Updated: 2025/02/21 21:37:28 by ababdoul         ###   ########.fr       */
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

void *function()
{
    static int i = 0;
    printf("thread detected ****  : %d\n", i);
    i++;    
    sleep(2);
    printf("end of thread !!\n");
}
int main(int ac , char **av)
{
    pthread_t id1, id2, id3;

    // printf("first thread id : %d\n",pthread_create(&id1, NULL, &function, NULL));
    if (pthread_create(&id1, NULL, &function, NULL) != 0)
        return (1);
    // printf("seconde thread id : %d\n",pthread_create(&id2, NULL, &function, NULL));
    if (pthread_create(&id2, NULL, &function, NULL) != 0)
        return  (2);
    // printf("third thread id : %d\n",pthread_create(&id3, NULL, &function, NULL));
    if (pthread_create(&id3, NULL, &function, NULL))
        return (3);
    pthread_join(id1, NULL);
    pthread_join(id2, NULL);
    pthread_join(id3, NULL);
}