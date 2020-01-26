#include "que.h"

Node newNode(int data)
{
    Node n;
    n.data = data;
    n.next = NULL;
    return n;
};

Queue newQ()
{
    Queue q;
    q.first = NULL;
    q.last = NULL;
    q.size = 0;
    return q;
};

bool isEmptyQ(Queue q)
{
    if (q.size == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
};

Queue delQ(Queue q)
{
    //let's check if queue is empty or not
    //if yes then return q

    if (isEmptyQ(q))
    {
        return q;
    }
    else if (q.size == 1)
    {
        q.first = NULL;
        q.last = NULL;
        q.size = 0;
        return q;
    }
    else
    {
        q.first = q.first->next;
        q.size--;
        return q;
    }
};

Node front(Queue q)
{
    return *(q.first);
};

Queue addQ(Queue q, Node e)
{
    //let us declare memory for the new node that we want to add
    // arrow is for value and dot is for accessing element

    Node *newElement = malloc(sizeof(Node));
    newElement->data = e.data;
    newElement->next = e.next;
    if (isEmptyQ(q))
    {
        q.size = 1;
        q.first = q.last = newElement;
    }
    else
    {
        q.size++;
        q.last->next = newElement;
        q.last = newElement;
    }
    return q;
};
int lengthQ(Queue q)
{
    return q.size;
};
