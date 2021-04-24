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

int partition(int list[], int left, int right) {
	int pivot, temp, low, high;
	low = left-1;
	high = right;

	//교수님은 이 부분은 partition 밖에서 해서, 변수 k로 index를 넘겨주는 방식 사용
	int pivotIndex = rand() % (right - left + 1) + left;
	pivot = list[pivotIndex];
	SWAP(list[pivotIndex], list[right], temp);

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

	SWAP(list[low], list[right], temp);
	return low;
}
void quickSort(int list[], int left, int right) {
	if (left < right) {
		int q = partition(list, left, right);
		quickSort(list, left, q - 1);
		quickSort(list, q + 1, right);
	}
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
	quickSort(list, 0, SIZE - 1);
	printArray(list, SIZE);
}