#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 11

printArray(int arr[], int n) {
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

//my code
/*
void shellSort(int list[], int n) {
	int gap = n / 2;
	
	int i, j, save;
	while (gap > 0) {
		if (gap % 2 == 0) gap++;

		for (int sub = 0; sub < gap; sub++) {
			for (int i = sub + gap; i < n; i += gap) {
				save = list[i];
				for (j = i-gap; j >= sub && list[j] > save; j -= gap) {
					list[j + gap] = list[j];
				}
				list[j + gap] = save;
			}
		}

		gap /= 2;
	}
}
*/

//prof - 원리 일치(while->for, 함수 2개로 나누기)
void inc_insertion_sort(int list[], int first, int last, int gap) {
	int i, j, key;
	for (i = first + gap; i < last; i += gap) {
		key = list[i];
		for (j = i - gap; j >= first && list[j] > key; j -= gap)
			list[j + gap] = list[j];
		list[j + gap] = key;
	}
}
void shellSort(int list[], int n) {
	int i, gap;
	for (gap = n / 2; gap > 0; gap /= 2) {
		if (gap % 2 == 0) gap++;
		for (i = 0; i < gap; i++)
			inc_insertion_sort(list, i, n - 1, gap);
	}
}


void main() {
	int list[SIZE];
	srand(time(NULL));
	for (int i = 0; i < SIZE; i++) {
		list[i] = rand() % 100;
		for (int j = 0; j < i; j++)
			if (list[i] == list[j])
				i--;
	}

	printArray(list, SIZE);
	shellSort(list, SIZE);
	printArray(list, SIZE);

}