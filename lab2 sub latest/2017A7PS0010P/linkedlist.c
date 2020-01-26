#include "linkedlist.h"
void insertFirst(struct linkedList *head, int elem)
{
	//creating a node
	struct node *link = (struct node *)malloc(sizeof(struct node));
	link->element = elem;
	link->next = head->first;
	head->first = link;
	head->count++;
}

struct node *deleteFirst(struct linkedList *head)
{
	struct node *temp = head->first;
	head->first = temp->next;
	head->count--;
	return temp;
}

int search(struct linkedList *head, int elem)
{
	struct node *temp = head->first;
	while (temp != NULL)
	{
		if (temp->element == elem)
			return 1;
		temp = temp->next;
	}
	return 0;
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

struct node *delete (struct linkedList *head, int elem)
{
	struct node *prev = head->first;
	struct node *temp = head->first;

	while (temp != NULL)
	{
		if (temp->element == elem)
		{
			head->count--;
			if (temp == head->first)
			{
				head->first = temp->next;
				return temp;
			}
			else
			{
				prev->next = temp->next;
				return temp;
			}
		}
		prev = temp;
		temp = temp->next;
	}

	printf("Element couldn't be found!\n");
	return NULL;
}
