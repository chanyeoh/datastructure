#include <stdlib.h>
#include <stdio.h>

struct stackNode{
	int data;
	struct stackNode *next;
};

/**
 * This function serves to be a stack the next element on the stack.
 */
void Push(struct stackNode **S, int data){
	struct stackNode *newNode = malloc(sizeof(struct stackNode));
	newNode->data = data;
	newNode->next = *S;
	*S = newNode;
}

/**
 * This function gives the most top element
 */
int Top(struct stackNode **S){
	return (*S)	->data;
}

/**
 * This functions serves to get the first element from the 
 * stack and remove it
 */
int Pop(struct stackNode **S){
	int popData = (*S)->data;
	*S = (*S)->next;
	return popData;
}

/**
 * This function prints out the current stack
 */
void printStack(struct stackNode **S){
	struct stackNode *items = *S;
	while(items != NULL){
		printf("%d ", items->data);
		items = items->next;
	}
	printf("\n");
}

int main(int argc, char** argv)
{
	struct stackNode *stack = NULL;
	Push(&stack, 5);
	Push(&stack, 4);
	Push(&stack, 3);
	Push(&stack, 2);

	printf("%d\n", Pop(&stack));
	printStack(&stack);

	return 0;
}