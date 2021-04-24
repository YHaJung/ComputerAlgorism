#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

void printArray(int list[], int n) {
	for (int i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n");
}

void merge(int list[], int start, int middle, int end) {
	int A[SIZE] = {0};
	int i = start, j = middle + 1;
	int k = start;
	while (i <= middle && j <= end) {
		if (list[i] <= list[j])
			A[k++] = list[i++];
		else
			A[k++] = list[j++];
	}
	while (i <= middle)
		A[k++] = list[i++];
	while (j <= end)
		A[k++] = list[j++];
	for (i = start; i < end + 1; i++) {
		list[i] = A[i];
	}
}

void mergeSort(int list[], int left, int right) {
	if (right <= left)
		return;
	int middle = (right + left) / 2;
	mergeSort(list, left, middle);
	mergeSort(list, middle + 1, right);
	merge(list, left, middle, right);
}

void main() {
	int arr[10] = { 1, 4, 8, 2, 3, 5, 11, 6, 9 };
	mergeSort(arr, 0, 8);
	printArray(arr, 9);
}