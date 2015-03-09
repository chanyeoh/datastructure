#include <stdlib.h>
#include <stdio.h>



struct queueNode{
	int data;
	struct queueNode *next;
	struct queueNode *last;
};

void enqueue(struct queueNode **S, int data){
	struct queueNode *newNode = malloc(sizeof(struct queueNode));
	newNode->data = data;
	newNode->next = NULL;
	newNode->last = newNode;
	if(*S == NULL){
		*S = newNode;
	}else{
		(*S)->last->next = newNode;
		(*S)->last = newNode;
	}
}

int dequeue(struct queueNode **S){
	int dequeueData = (*S)->data;
	struct queueNode *last = (*S)->last;
	
	*S = (*S)->next;
	if(*S != NULL)
		(*S)->last = last;

	return dequeueData;
}

int front(struct queueNode **S){
	int dequeueData = (*S)->data;
	return dequeueData;
}


int main(int argc, char** argv)
{
	struct queueNode *queue = NULL;
	enqueue(&queue, 5);
	enqueue(&queue, 4);
	enqueue(&queue, 3);
	enqueue(&queue, 2);

	printf("%d\n", dequeue(&queue));
	printf("%d\n", dequeue(&queue));
	printf("%d\n", dequeue(&queue));
	printf("%d\n", dequeue(&queue));

	return 0;
}