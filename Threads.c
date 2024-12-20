This C code demonstrates the use of POSIX threads (pthreads) to create and manage multiple threads. 
The program creates 5 threads, each executing the same function (threadFunction), 
and then ensures all threads complete their execution before the program terminates.


CODE => 
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Function to be executed by each thread
void* threadFunction(void* arg) {
    int thread_id = *((int*)arg);
    printf("Thread %d: Hello, I am a thread!\n", thread_id);
    return NULL;
}

int main() {
    pthread_t threads[5]; // Array to hold thread identifiers
    int thread_ids[5];    // Array to hold thread IDs
    int i;

    // Creating 5 threads.
    for (i = 0; i < 5; i++) {
        thread_ids[i] = i + 1; // Assign thread ID
        if (pthread_create(&threads[i], NULL, threadFunction, &thread_ids[i]) != 0) {
            printf("Error creating thread %d\n", i + 1);
            return 1;
        }
    }

    // Joining the threads to ensure they complete
    for (i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads completed.\n");
    return 0;
}
