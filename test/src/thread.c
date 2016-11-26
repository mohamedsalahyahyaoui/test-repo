#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// A normal C function that is executed as a thread when its name
// is specified in pthread_create()
void *myThreadFun(void *vargp)
{
    sleep(15);
    printf("Printing GeeksQuiz from Thread \n");
    while (1 == 1) {
      printf("still waiting\n" );
      sleep(5);
        }
}
int main()
{
    pthread_t tid;
    printf("Before Thread\n");
    pthread_create(&tid, NULL, myThreadFun, NULL);
    pthread_join(tid, NULL);
    printf("After Thread\n");
    exit(0);
}
