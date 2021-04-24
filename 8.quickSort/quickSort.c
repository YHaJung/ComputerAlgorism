#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 15
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y=t))


void printArray(int A[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
}

//prof.
int partition(int list[], int left, int right) {
	int pivot, temp, low, high;
	low = left;
	high = right + 1;
	pivot = list[left];
	do {
		do
			low++;
		while (list[low] < pivot);
		do 
			high--;
		while (list[high] > pivot);

		if (low < high)
			SWAP(list[low], list[high], temp);

	} while (low < high);

	SWAP(list[left], list[high], temp);
	return high;
}
void quickSort(int list[], int left, int right) {
	if (left < right) {
		int q = partition(list, left, right);
		quickSort(list, left, q - 1);
		quickSort(list, q + 1, right);
	}
}

//my
void quickSort2(int list[], int start, int end) {
	int temp;

	if (end - start < 1) return;
	else if (end - start == 1) {
		if (list[start] > list[end])
			SWAP(list[start], list[end], temp);
		return;
	}

	int q = list[start];
	int left = start + 1, right = end;
	
	while (left < right) {
		while (list[left] < q)
			left++;
		while (list[right] > q)
			right--;
		if (left < right) SWAP(list[left], list[right], temp);
		//printArray(list, SIZE);
	}
	SWAP(list[start], list[right], temp);
	//printf("%d:%d, %d:%d, %d:%d\n", start, q, left, list[left], right, list[right]);

	quickSort2(list, start, right - 1);
	quickSort2(list, right + 1, end);
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
	quickSort(list, 0, SIZE-1);
	printArray(list, SIZE);
}