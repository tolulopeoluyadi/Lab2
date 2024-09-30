#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

#define MAX_ITERATIONS 30
#define MAX_SLEEP 10

void childProcess() {
    int iterations = rand() % MAX_ITERATIONS;  
    pid_t pid = getpid();                      
    pid_t ppid = getppid();                    

    for (int i = 0; i < iterations; i++) {
        int sleepTime = rand() % MAX_SLEEP;    
        printf("Child Pid: %d is going to sleep for %d seconds!\n", pid, sleepTime);
        sleep(sleepTime);                      
        printf("Child Pid: %d is awake! Where is my Parent: %d?\n", pid, ppid);
    }

    printf("Child Pid: %d has finished execution.\n", pid);
    exit(0);                                   
}

int main() {
    srand(time(NULL));                         

    pid_t child1, child2;

    // Create first child process
    if ((child1 = fork()) == 0) {
        childProcess();
    }

    // Create second child process
    if ((child2 = fork()) == 0) {
        childProcess();
    }

    
    int status;
    waitpid(child1, &status, 0);
    printf("Child Pid: %d has completed.\n", child1);

    waitpid(child2, &status, 0);
    printf("Child Pid: %d has completed.\n", child2);

    return 0;
}
