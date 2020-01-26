#include "multiq.h"

MultiQ createMQ(int num)
{
    MultiQ mq;
    mq.size = num;
    mq.qarr = malloc(sizeof(Queue) * num);
    return mq;
}

MultiQ addMQ(MultiQ mq, Task t)
{
    Node n1 = newNode(t.tid);
    mq.qarr[t.p - 1] = addQ(mq.qarr[t.p - 1], n1);
    return mq;
}
Task nextMQ(MultiQ mq)
{
    if (isEmptyMQ(mq))
    {
        Task emptyTask;
        emptyTask.tid = -1;
        emptyTask.p = -1;
        return emptyTask;
    }
    else
    {
        int i = mq.size - 1;
        while (isEmptyQ(mq.qarr[i]))
            i--;
        Task newTask;
        newTask.tid = front(mq.qarr[i]).data;
        newTask.p = i + 1;
        return newTask;
    }
}

MultiQ delNextMQ(MultiQ mq)
{
    if (isEmptyMQ(mq))
    {
        return mq;
    }
    else
    {
        int i = maxPriority - 1;
        while (isEmptyQ(mq.qarr[i]))
            i--;
        mq.qarr[i] = delQ(mq.qarr[i]);
        return mq;
    }
}
int sizeMQbyPriority(MultiQ mq, Priority p)
{
    return lengthQ(mq.qarr[p - 1]);
}

bool isEmptyMQ(MultiQ mq)
{
    for (int i = mq.size - 1; i >= 0; i--)
    {
        if (isEmptyQ(mq.qarr[i]))
        {
        }
        else
        {
            return false;
        }
    }
    return true;
}

Queue getQueueFromMQ(MultiQ mq, Priority p)
{
    return mq.qarr[p - 1];
}
int sizeMQ(MultiQ mq)
{
    int size = 0;
    for (int i = mq.size - 1; i >= 0; i--)
    {
        size += lengthQ(mq.qarr[i]);
    }
    return size;
}
