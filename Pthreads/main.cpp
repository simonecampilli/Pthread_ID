#include <iostream>
using namespace std;

#include <pthread.h>

void *my_pthread_fn(void *arg) {
    cout << "\t\t\t\t Hello Pthreads world. I am another thread" << endl;
}


int main()
{
    pthread_t myid;
    pthread_attr_t attr;
    int ret;
    void *retval;

    cout << "hello Pthread world! i am the main thread";

    ret = pthread_attr_init(&attr);

    ret = pthread_create(&myid,
                              &attr,
                              my_pthread_fn,
                              NULL);

    ret = pthread_attr_destroy(&attr);

    pthread_join(myid, &retval);


    return 0 ;
}
