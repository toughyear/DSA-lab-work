#include <cycle.h>

int testCyclic(struct linkedList* list){
	struct node* fast = list->first;
	struct node* slow = list->first;

	if(fast==NULL){
		return 0;
	}

	while(fast->next != NULL && fast->next->next !=NULL){
		slow = slow->next;
		fast = fast->next->next;
		if(slow==fast){
			return 1;
		}
	}

	return 0;

}