#include <stdlib.h>
#include <stdio.h>

struct bstNode{
	int data;
	struct bstNode *left;
	struct bstNode *right;
};

void insert(struct bstNode **bst, int data){
	if(*bst == NULL){
		struct bstNode *newNode = malloc(sizeof(struct bstNode));
		newNode->data = data;
		newNode->left = NULL;
		newNode->right = NULL;
		*bst = newNode;
	}else{
		if(data > (*bst)->data){
			insert(&(*bst)->right, data);
		}else{
			insert(&(*bst)->left, data);
		}
	}
}

struct bstNode *find(struct bstNode **bst, int data){
	if(*bst == NULL)
		return NULL;

	printf("%d\n", (*bst)->data);
	if((*bst)->data == data){
		return (*bst);
	}

	if(data > (*bst)->data){
		return find(&(*bst)->right, data);
	}

	return find(&(*bst)->left, data);
	
}

void delete(struct bstNode **bst, int data){
	struct bstNode *nodeData = find(bst, data);
	if(nodeData == NULL)
		return;

	struct bstNode *smallestNode = nodeData->right;
	struct bstNode *lagNode = NULL;
	while(smallestNode->left != NULL){
		lagNode = smallestNode;
		smallestNode = smallestNode->left;
	}

	if(lagNode != NULL){
		lagNode->left = NULL;
	}
	nodeData->data = smallestNode->data;
	printf("%d\n", smallestNode->data);
}

int main(int argc, char** argv)
{
	struct bstNode *bst = NULL;
	insert(&bst, 50);
	insert(&bst, 45);
	insert(&bst, 49);
	insert(&bst, 48);
	insert(&bst, 46);
	insert(&bst, 44);
	
	insert(&bst, 55);
	insert(&bst, 58);
	insert(&bst, 53);

	delete(&bst, 45);
	printf("-----\n");
	find(&bst, 44);
	insert(&bst, 47);
	printf("-----\n");
	find(&bst, 47);

	return 0;
}