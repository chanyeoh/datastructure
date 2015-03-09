#include <stdlib.h>
#include <stdio.h>


int left_child(int value, int length){
	int left = 2 * (value + 1) - 1;
	if (left >= length){
		return -1;
	}
	return left;
}

int right_child(int value, int length){
	int right = 2*(value+1);
	if (right >= length){
		return -1;
	}
	return right;
}

int parent(int value){
	if(value <= 0)
		return 0;
	return (value - 1)/2;
}


void down_heap(int **heap, int value, int length){
	int largestIndex, temp;
	int currPointer = value;

	while(left_child(currPointer, length) != -1){
		largestIndex = left_child(currPointer, length);

		if (right_child(currPointer, length) != -1){
			if((*heap)[right_child(currPointer, length)] > (*heap)[left_child(currPointer, length)]){
				largestIndex = right_child(currPointer, length);
			}
		}

		if((*heap)[largestIndex] <= (*heap)[currPointer]){
			break;
		}

		temp = (*heap)[largestIndex];
		(*heap)[largestIndex] = (*heap)[currPointer];
		(*heap)[currPointer]  = temp;

		currPointer = largestIndex;
	}
}


void make_heap(int **heap, int length){
	int value = length - 1;
	while (value != -1){
		down_heap(&(*heap), parent(value),length);
		value = value - 1;
	}
}


int extract_max(int **heap, int *length){
	int maxValue = (*heap)[0];
	(*heap)[0] = (*heap)[*length - 1];
	*length = *length - 1;
	if(*length <= 0)
		return maxValue;
	down_heap(&(*heap), 0, *length);
	return maxValue;
}



int main(int argc, char** argv)
{
	int length = 4;
	int *heap = malloc(sizeof(int) * length);
	heap[0] = 3;
	heap[1] = 5;
	heap[2] = 2;
	heap[3] = 1;
	make_heap(&heap, length);
	
	for (int i = 0; i < 4; ++i)
	{
		printf("%d\n", extract_max(&heap, &length));
	}

	return 0;
}