

#include "linkedlist.h"

void insertFirst(struct linkedList *head, int element)
{

	struct node *a = (struct node *)myalloc(sizeof(struct node));
	a->element = element;

	a->next = head->first;

	head->first = a;
	head->count++;
}

void insertLast(struct linkedList *head, int element)
{

	struct node *a = (struct node *)myalloc(sizeof(struct node));
	a->element = element;

	struct node *traverse = head->first;
	if (traverse == NULL)
	{
		head->first = a;
		return;
	}

	while (traverse->next != NULL)
	{
		traverse = traverse->next;
	}

	traverse->next = a;

	head->count++;
}

struct node *deleteFirst(struct linkedList *head)
{
	struct node *temp = head->first;
	head->first = temp->next;
	head->count--;
	return temp;
}

void printList(struct linkedList *head)
{
	struct node *ptr = head->first;
	printf("\n[ ");

	while (ptr != NULL)
	{
		printf("%d, ", ptr->element);
		ptr = ptr->next;
	}
	printf(" ]");
}

struct linkedList *createList(int N)
{
	struct linkedList *list = (struct linkedList *)myalloc(sizeof(struct linkedList));
	list->count = 0;
	list->first = NULL;
	int random;
	for (int i = 0; i < N; i++)
	{

		random = rand();
		insertFirst(list, random);
	}
	return list;
}

struct linkedList *createCycle(struct linkedList *head)
{
	int random = rand();
	if (random > RAND_MAX / 2)
	{
		printf("NOT CYCLIC.\n");
		return head;
	}
	else
	{
		printf("CYCLIC.\n");
		int arr[head->count];
		int i = 0;
		struct node *traverse = head->first;
		while (traverse->next != NULL)
		{
			arr[i] = traverse->element;
			i++;
			traverse = traverse->next;
		}

		random = rand();
		double ratio = ((double)head->count) / RAND_MAX;
		random *= ratio;

		int tocycle = arr[random];
		struct node *tocyclenode = NULL;
		traverse = head->first;

		while (traverse->next != NULL)
		{
			if (traverse->element == tocycle)
			{
				tocyclenode = traverse;
			}
			traverse = traverse->next;
		}

		traverse->next = tocyclenode;
		return head;
	}
}

struct node *search(struct linkedList *head, int element)
{
	struct node *traverse = head->first;
	while (traverse != NULL)
	{
		if (traverse->element == element)
		{
			return traverse;
		}
		traverse = traverse->next;
	}
	return traverse;
}
