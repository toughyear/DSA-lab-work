// let's try the simple queue structure we have made

#include "que.h"

int main()
{
    //create a new empty queue
    Queue q = newQ();
    // let's add a new element
    Node new;
    new.data = 20;
    new.next = NULL;
    q = addQ(q, new);

    // let's add another element
    Node new2;
    new2.data = 33;
    new2.next = NULL;
    q = addQ(q, new2);
    printf("element 1 value: %d\n", front(q).data);
    printf("element 2 value: %d\n", front(q).next->data);
    q = delQ(q);

    printf("element 1 value: %d\n", front(q).data);
    printf("element 2 value: %d\n", front(q).next->data);

    return 0;
}