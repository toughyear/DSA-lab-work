#include "que.h"
#define maxPriority 10

typedef struct
{
    //size is total number of priorities
    int size;
    // let's create an array of pointers to each of the queue
    // this is how we do in c
    Queue *qarr;
} MultiQ;

typedef int Priority;
typedef int TaskID;

typedef struct
{
    TaskID tid;
    Priority p;
} Task;

MultiQ createMQ(int num);
MultiQ addMQ(MultiQ mq, Task t);
Task nextMQ(MultiQ mq);
MultiQ delNextMQ(MultiQ mq);
bool isEmptyMQ(MultiQ mq);
int sizeMQ(MultiQ mq);
int sizeMQbyPriority(MultiQ mq, Priority p);
Queue getQueueFromMQ(MultiQ, Priority p); //
