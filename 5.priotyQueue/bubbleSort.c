#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))
#define SIZE 15


printArray(int arr[], int n) {
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

/*단계별 출력 제외하면, 교수님이 한 것과 완전히 일치*/
void bubbleSort(int list[], int n) {
	printf("정렬할 원소 : ");
	printArray(list, SIZE);

	printf("<<<<버블정렬 수행>>>>\n");
	int temp;
	for (int i = n; i > 1; i--) {
		for (int j = 0; j < i-1; j++) {
			if (list[j] > list[j + 1])
				SWAP(list[j], list[j + 1], temp);
		}
		printf("%d단계 : ", n - i + 1);
		printArray(list, SIZE);
	}
}

void main() {
	int list[SIZE];
	srand(time(NULL));
	for (int i = 0; i < SIZE; i++)
		list[i] = rand() % 100;

	
	bubbleSort(list, SIZE);
	
}