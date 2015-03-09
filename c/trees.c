#include <stdlib.h>
#include <stdio.h>

struct TreeNodeInfo{
	int data;
	int parent;
};

static int length = 0;
static int size = 0;

void printTree(struct TreeNodeInfo *tree){
	for (int i = 0; i < length; ++i)
	{
		printf("%d\n", tree[i].data);
	}
}

int find(struct TreeNodeInfo *tree, int data){
	for (int i = 0; i < length; ++i)
	{
		if(tree[i].data == data){
			return i;
		}
	}
	return -1;
}

void insertAtEmptySlot(struct TreeNodeInfo **tree, struct TreeNodeInfo newNode){
	for (int i = 0; i < length; ++i)
	{
		if((*tree)[i].data == 0){
			(*tree)[i] = newNode;
			return;
		}
	}
}

void insert(struct TreeNodeInfo **tree, int data, int parentData){
	if((*tree) == NULL){
		length = 3;
		(*tree) = (struct TreeNodeInfo *) malloc(sizeof(struct TreeNodeInfo) * length);
		for (int i = 0; i < length; ++i)
		{
			(*tree)[i].data = 0;
		}
	}

	if(size >= length){
		length = length + 2;
		(*tree) = (struct TreeNodeInfo *) realloc(*tree, sizeof(struct TreeNodeInfo) * length);
		for (int i = size; i < length; ++i)
		{
			(*tree)[i].data = 0;
		}
	}

	struct TreeNodeInfo *newNode = malloc(sizeof(struct TreeNodeInfo));
	newNode->data = data;
	newNode->parent = -1;

	if(size != 0){
		int index = find(*tree, parentData);
		if(index == -1)
			return;

		newNode->parent = index;
	}

	insertAtEmptySlot(&(*tree), *newNode);

	size = size + 1;
}

void delete(struct TreeNodeInfo **tree, int data){
	for (int i = 0; i < length; ++i)
	{
		if((*tree)[i].data == data){
			(*tree)[i].data = 0;
			(*tree)[i].parent = -1;
			size = size - 1;
			return;
		}
	}
}

int findParent(struct TreeNodeInfo **tree, int data){
	for (int i = 0; i < length; ++i)
	{
		if((*tree)[i].data == data){
			int parent = (*tree)[i].parent;
			if( parent == -1)
				return -1;
			return (*tree)[parent].data;
		}
	}
	return -1;
}

void findChild(struct TreeNodeInfo **tree, int parentData){
	int index = find(*tree, parentData);
	for (int i = 0; i < length; ++i)
	{
		if((*tree)[i].parent == index){
			printf("%d ", (*tree)[i].data);
		}
	}
	printf("\n");
}



int main(int argc, char** argv)
{
	struct TreeNodeInfo *tree = NULL;
	insert(&tree, 5, -1);
	insert(&tree, 3, 5);
	insert(&tree, 4, 5);

	delete(&tree, 4);
	insert(&tree, 2, 5);

	printf("%d\n", findParent(&tree, 2));
	findChild(&tree, 5);


	return 0;
}