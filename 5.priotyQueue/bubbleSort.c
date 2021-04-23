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

/*�ܰ躰 ��� �����ϸ�, �������� �� �Ͱ� ������ ��ġ*/
void bubbleSort(int list[], int n) {
	printf("������ ���� : ");
	printArray(list, SIZE);

	printf("<<<<�������� ����>>>>\n");
	int temp;
	for (int i = n; i > 1; i--) {
		for (int j = 0; j < i-1; j++) {
			if (list[j] > list[j + 1])
				SWAP(list[j], list[j + 1], temp);
		}
		printf("%d�ܰ� : ", n - i + 1);
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