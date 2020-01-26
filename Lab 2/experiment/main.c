#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main(int argc, char *argv[])
{

    // file pointer called data will read data from a file something.txt in order to make a linked list
    FILE *data = fopen(argv[1], "r");

    /*declare a head of the linked list that will have count of total elements in the list as well as the pointer to the first element
    here head is a pointer that points to a structure we made called linkedList. linkedList (structure we defined) act as head for the
    linked list */
    struct linkedList *head = (struct linkedList *)malloc(sizeof(struct linkedList));

    // feof(filePointer) returns true when end of file is reached in filePointer's stream.
    while (!feof(data))
    {
        int temp;

        // when you scan you store the value as &var not var when reading from format specifier.
        fscanf(data, "%d", &temp);
        //insert temp into the linked list
        insertFirst(head, temp);
    }

    fclose(data);
    /**/

    //print the formed linked list
    printList(head);
    //delete the first item
    deleteFirst(head);
    //check if deletion was successful
    printList(head);

    //copy the linked list to a new file
    FILE *dest = fopen("output.txt", "w");
    struct node *temp = head->first;
    while (temp->next != NULL)
    {
        fprintf(dest, "%d -> ", temp->element);
    }
    fprintf(dest, "%d end of the list", temp->element);

    fclose(dest);

    return 0;
}
