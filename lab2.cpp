#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>

int balance = 1000;  
sem_t sem;

void *deposit(void *arg);
void *withdraw(void *arg);

int main() {
    sem_init(&sem, 0, 1); 
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, deposit, NULL);
    pthread_create(&thread2, NULL, withdraw, NULL);

   

    printf("Final balance is %d\n", balance);

    sem_destroy(&sem); 
    return 0;
}

void *deposit(void *arg) {
    sem_wait(&sem); 
    int temp = balance; 
    temp += 500; 
    sleep(1); 
    balance = temp;
    printf("Balance after deposit is %d\n", balance);
    sem_post(&sem); 
    return NULL;
}

void *withdraw(void *arg) {
    sem_wait(&sem); 
    int temp = balance; 
    temp -= 200; 
    sleep(1); 
    balance = temp; 
    printf("Balance after withdrawal is %d\n", balance);
    sem_post(&sem); 
    return NULL;
}