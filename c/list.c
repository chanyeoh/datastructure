#include <stdlib.h>
#include <stdio.h>


static int size = 0;

struct listNode{
	int data;
	struct listNode *next;
};

/**
 * This function is used to add an object at the given position
 * and insert it to the list without changing the much of it.
 */
void insert(struct listNode **L, int position, int data){
	// If the Position is -1, then don't even bother adding it
	if(position == -1)
		return;

	// Set up the new data
	struct listNode *newNode = malloc(sizeof(struct listNode));
	newNode->data = data;
	newNode->next = NULL;

	if(*L == NULL){
		*L = newNode;
	}else{
		struct listNode **nextList = L;
		struct listNode *lastItem = NULL;
		int i=0;
		// Loop through the list
		while( *nextList != NULL){
			// Check for the position
			if(i == position){
				lastItem = *nextList;
				break;
			}
			nextList = &(*nextList)->next;
			i ++;
		}
		newNode->next = lastItem;
		*nextList = newNode;
	}

	// Increase the size
	size = size + 1;
}

/**
 * This function is used to delete an object of a given data
 */
void delete(struct listNode **L, int data){
	struct listNode **nextList = L;
	struct listNode *laggingPointer = NULL;
	int isFound = 0;

	// Keep looping until the element is found
	while( *nextList != NULL){
		// We have found the element
		if((*nextList)->data == data){
			isFound = 1;
			nextList = &(*nextList)->next;
			break;
		}
		laggingPointer = *nextList;
		nextList = &(*nextList)->next;
	}

	// If element is not found return it 
	if(!isFound)
		return;

	// Check if it is at the beginning of the lsit
	// or at the end 
	if(laggingPointer == NULL){
		*L = (*nextList);
	}else{
		laggingPointer->next = *nextList;
	}

	// Decrease the size
	size = size - 1;
}

/**
 * This function serves to return the size of the list
 */
int getSize(){
	return size;
}

/**
 * This list serves to find the location of the 
 * first occurence of a given list
 */
int locate(struct listNode **L, int data){
	struct listNode **nextList = L;
	int i = 0;
	// Keep looping until the element is found
	while( *nextList != NULL){
		if((*nextList)->data == data){
			return i;
		}

		nextList = &(*nextList)->next;
		i ++;
	}

	return -1;
}

/**
 * This function prints the list
 */
void printList(struct listNode ** L){
	struct listNode *items = *L;
	while(items != NULL){
		printf("%d ", items->data);
		items = items->next;
	}
	printf("\n");
}

int main(int argc, char** argv)
{
	struct listNode *list = NULL;
	insert(&list, 0, 5);
	insert(&list, 1, 4);
	insert(&list, 2, 3);
	insert(&list, 1, 2);

	delete(&list, 3);

	printList(&list);
	//printf("%d\n", locate(&list, 3));

	return 0;
}