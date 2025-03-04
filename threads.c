#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include "philo/philosopher.h"

int amount = 0;
pthread_mutex_t mutex;
void write_new_amount(int new_amount)
{
    usleep(2500);
    amount = new_amount;
}
int read_ballance()
{
    usleep(25000);
    return (amount);
}
void *ballance(void *amount)
{
    pthread_mutex_lock(&mutex);
    int ballance_account = read_ballance();
    ballance_account += (*(int *)amount);
    write_new_amount(ballance_account);
    pthread_mutex_unlock(&mutex);
    return (NULL);
}
int main()
{
    pthread_t i;
    pthread_t j;

    int deposite_1;
    int deposite_2;

    deposite_1 = 300;
    deposite_2 = 200;
    int before = read_ballance();
    printf("before deposite: %d\n", before);
    pthread_mutex_init(&mutex, NULL);
    pthread_create(&i, NULL, ballance, (void *)&deposite_1);
    pthread_create(&j , NULL, ballance, (void *)&deposite_2);

    pthread_join(j, NULL);
    pthread_join(i, NULL);
    int after = read_ballance();
    printf("after deposite: %d\n", after);
    pthread_mutex_destroy(&mutex);
    // printf("mails = %d\n", mails);
    return (0);
}

