#include <pthread.h>
#include <unistd.h>
#include <iostream>

static void print_thread() {
    pid_t pid;
    pthread_t tid;
    pid = getpid();
    tid = pthread_self();
    std::cout << "pid:" << pid << " tid:" << tid << std::endl;
}

static void *thr_fn(void *arg) {
    print_thread();
    return (void *)NULL;
}

int main(int argc, char *argv[], char *env[]) {
    int err;
    pthread_t tid;
    pthread_create(&tid, NULL, thr_fn, NULL);
    print_thread();
    sleep(1);
    return 0;
}
