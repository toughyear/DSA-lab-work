#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
int main(int argc, char *argv[])
{

	FILE *fileptr = fopen(argv[1], "r");

	struct linkedList *head = (struct linkedList *)malloc(sizeof(struct linkedList));

	while (!feof(fileptr))
	{

		int temp;
		fscanf(fileptr, "%d ", &temp);

		insertFirst(head, temp);
	}

	fclose(fileptr);

	printList(head);

	printf("Deleted : %d\n.", deleteFirst(head)->element);

	printList(head);

	FILE *new_file_ptr = fopen(argv[2], "w");
	struct node *ptr = head->first;
	while (ptr != NULL)
	{
		fprintf(new_file_ptr, "%d\n", ptr->element);
		ptr = ptr->next;
	}
	fclose(new_file_ptr);
}