#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

// let us implement the functions one by one

// insertFirst

void insertFirst(struct linkedList *head, int ele)
{
    // create a node to keep the value in

    struct node *link = (struct node *)malloc(sizeof(struct node));
    /* by this you are creating a node whose address is being stored in the link pointer. */

    // now link is a new pointer which points to a new struct Node, size for which has been allocated in the memory.

    link->element = ele;

    // -> function acts same as dot function in javascript, i.e. link.element is now equal to ele.

    link->next = head->first;

    // above line means link.next now equals to head.first

    head->first = link;
    head->count++;
}

void deleteFirst(struct linkedList *head)
{
    // head.first should be equal to head.first.next so that (first node) is out/deleted.
    head->first = head->first->next;
    head->count--;
}

void printList(struct linkedList *head)
{
    struct node *temp = head->first;
    int v = 9;
    while (v--)
    {
        printf("element: %d\n", temp->element);
        temp = temp->next;
    }
}

void search(struct linkedList *head, int ele)
{
    struct node *temp = head->first;

    int pos = 1;
    while (temp->element != ele || temp->next != NULL)
    {
        temp = temp->next;
        pos++;
    }

    if (temp->next == NULL)
    {
        printf("the element you searched for was not found!");

        //this exit doesn't return any value to the calling function, it just sends a status: function exited with code 0. it means nothing.
        // exit(12344) would work just fine
        exit(0);
    }

    printf("the position of the searched element is: %d", pos);
}
