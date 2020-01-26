#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// let us define node structure for making queue

struct node
{
    int data;
    struct node *next;
};

// we don't want to use every time struct node
// so let's introduce shorter way to name it

typedef struct node Node;

// let's make a function that can add nodes as and when needed

Node newNode(int data);

// we want to make a struct that will have two pointers, one at start of list and one at last
// so that we can access both first and last element
struct queue
{
    Node *first;
    Node *last;
    int size;
};

// so let's introduce shorter way to name it

typedef struct queue Queue;

// function that returns an empty queue
Queue newQ();

// function that tests if queue is empty
bool isEmptyQ(Queue q);

//function to delete the element from the front of the given queue

Queue delQ(Queue q);

// function to return the front element of the queue
Node front(Queue q);

// adding element q at the rear of the queue

Queue addQ(Queue q, Node e);

// function to return the length of the queue

int lengthQ(Queue q);
