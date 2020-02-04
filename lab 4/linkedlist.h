#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node
{
	int element;
	struct node *next;
};

struct linkedList
{
	int count;
	struct node *first;
};

void *myalloc(int x);
void myfree(void *x);
struct linkedList *createList(int N);

struct linkedList *createCycle(struct linkedList *head);
void insertFirst(struct linkedList *head, int element);

void insertLast(struct linkedList *head, int element);

struct node *deleteFirst(struct linkedList *head);

void printList(struct linkedList *head);

struct node *search(struct linkedList *head, int element);
