#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 15

inplaceInsertionSort(int list[]) {
	int j, save;
	for (int i = 1; i < SIZE; i++) {
		j = i - 1;
		save = list[i];
		while (j >= 0 && list[j] > save) {
			list[j + 1] = list[j];
			j--;
		}
		list[j+1] = save;
	}
}

//prof. 원리상 같음. 오직 for이냐 while이냐 차이
/*
inplaceInsertionSort(int list[]) {
	int i, j, save;
	for (i = 1; i < SIZE; i++) {
		save = list[i];
		for(j=i-1; j >= 0 && list[j] > save; j--) {
			list[j + 1] = list[j];
		}
		list[j+1] = save;
	}
}
*/


printArray(int arr[]) {
	for (int i = 0; i < SIZE; i++)
		printf("%d ", arr[i]);
	printf("\n");
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

	printArray(list);
	inplaceInsertionSort(list);
	printArray(list);
}
