#include <pthread.h>
#include <unistd.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>

static void* thr_fn1(void *arg) {
    std::cout << "thread 1 return" << std::endl;
    return((void *)1);
}

static void* thr_fn2(void *arg) {
    std::cout << "thread 2 return" << std::endl;
    pthread_exit((void *)2);
}

int main(int argc, char *argv[], char *env[]) {
    int err;
    pthread_t tid1, tid2;
    void *tret;
    err = pthread_create(&tid1, NULL, thr_fn1, NULL);
    if( err != 0) {
        perror(NULL);
        exit(0);
    }

    err = pthread_create(&tid2, NULL, thr_fn2, NULL);
    if( err != 0) {
        perror(NULL);
        exit(0);
    }

    err = pthread_join(tid1, &tret);
    if( err != 0) {
        perror(NULL);
        exit(0);
    }
    std::cout << tret << std::endl;

    err = pthread_join(tid2, &tret);
    if( err != 0) {
        perror(NULL);
        exit(0);
    }
    std::cout << tret << std::endl;

    return 0;
}
