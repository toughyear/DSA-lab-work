#include <stdio.h>
#include <stdlib.h>

// following is the structure of nodes for the linked list

struct node
{
    int element;
    struct node *next;
};

// Structure for the head of the linked list: it will have count of number of elements in the linkedlist and the pointer to the first element.

struct linkedList
{
    int count;
    struct node *first;
};

// function declarations for the header file: no need for full implementation of the functions

// first function: to insert a new element at the beginning of the list

// struct linkedList *head is a pointer to the head , the head has 2 values: count and a pointer. the pointer points to the first element of the list.

void insertFirst(struct linkedList *head, int ele);

// second function: to delete element at the beginning of the list

void deleteFirst(struct linkedList *head);

// third function: to print all the elements of the list

void printList(struct linkedList *head);

// fourth function: to search for a given element in the list

void search(struct linkedList *head, int ele);
