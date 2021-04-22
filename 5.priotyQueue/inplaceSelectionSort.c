#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 15
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y=t))

void swap(int A[], int a, int b) {
	int temp = A[a];
	A[a] = A[b];
	A[b] = temp;
}

void inplaceSelectionSort(int A[], int n) {
	int min;
	for (int i = 0; i < n - 1; i++) {
		min = i;
		for (int j = i; j < n; j++) {
			if (A[min] > A[j]) min = j;
		}
		swap(A, i, min);
	}
}

void printArray(int A[], int n) {
	for (int i = 0; i < n; i++)
		printf("%d ", A[i]);
	printf("\n");	
}

void main() {
	int list[SIZE];
	srand(time(NULL));
	for (int i = 0; i < SIZE; i++) {
		list[i] = rand() % 100;
		for (int j = 0; j < i; j++) {   //중복 방지. 여기선 굳이 필요 없음
			if (list[i] == list[j])
				i--;
		}
	}


	printArray(list, SIZE);
	inplaceSelectionSort(list, SIZE);
	printArray(list, SIZE);
}