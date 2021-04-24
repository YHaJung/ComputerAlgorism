#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 15
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y=t))

void printArray(int A[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%c ", A[i]);
	}
	printf("\n");
}

void colorPartition(int list[], int left, int right) {
	int low = left;
	int high = right;
	int temp;
	do {
		while (list[low] == 'B')
			low++;
		while (list[high] == 'R')
			high--;
		if (low < high) SWAP(list[low], list[high], temp);
		
		//printf("low:%d, high:%d\n",low, high);
		//printArray(list, SIZE);
	} while (low < high);

	
}

void main() {
	int list[SIZE];
	srand(time(NULL));
	int num;
	for (int i = 0; i < SIZE; i++) {
		num = rand() % 2;
		if (num == 0)
			list[i] = 'B';
		else
			list[i] = 'R';
	}

	printArray(list, SIZE);
	colorPartition(list, 0, SIZE - 1);
	printArray(list, SIZE);
}