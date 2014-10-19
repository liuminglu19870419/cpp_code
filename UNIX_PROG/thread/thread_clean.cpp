#include <pthread.h>
#include <unistd.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>

void cleanup(void *arg) {
    std::cout << "clean up:" << (char *) arg << std::endl;
}

void *thr_fn1(void *arg) {
    pthread_cleanup_push(cleanup, (void *)"1 first");
    pthread_cleanup_push(cleanup, (void *)"1 second");
    std::cout << "thread 1 pushed" << std::endl;
    if(arg)
        return ((void *)1);
    
    pthread_cleanup_pop(0);
    pthread_cleanup_pop(0);
    return (void *)1;
}

void *thr_fn2(void *arg) {
    pthread_cleanup_push(cleanup, (void *)"2 first");
    pthread_cleanup_push(cleanup, (void *)"2 second");
    std::cout << "thread 2 pushed" << std::endl;
    if(arg)
        pthread_exit((void *)2);
    
    pthread_cleanup_pop(0);
    pthread_cleanup_pop(0);
    pthread_exit((void *)2);
}
int main(int argc, char* argv[], char *env[]) {
    pthread_t tid;
    int err;
    pthread_create(&tid, NULL, thr_fn1, (void *)1);
    err = pthread_join(tid, NULL);

    pthread_create(&tid, NULL, thr_fn2, (void *)2);
    err = pthread_join(tid, NULL);
    return 0;
}
