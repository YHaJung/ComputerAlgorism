#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 15

void printArray(int A[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
}

void prefixAverages(int X[], int avgs[], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += X[i];
		printf("%d ", sum);
		avgs[i] = sum / (i + 1);
	}
	printf("\n");
}

void main() {
	int list[SIZE], avgs[SIZE];
	srand(time(NULL));
	for (int i = 0; i < SIZE; i++) {
		list[i] = rand() % 10;
	}

	printArray(list, SIZE);
	prefixAverages(list, avgs, SIZE);
	printArray(avgs, SIZE);
}