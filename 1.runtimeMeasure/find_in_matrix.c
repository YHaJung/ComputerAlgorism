#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 8
#define COLS 8

void makeArray(int A[][COLS]) {
	for (int r = 0; r < ROWS; r++)
		for (int c = 0; c < COLS; c++)
			A[r][c] = rand() % 100; //0~99 숫자 나옴
}

void printArray(int A[][COLS]) {
	for (int r = 0; r < ROWS; r++) {
		for (int c = 0; c < COLS; c++)
			printf("%2d ", A[r][c]); //%2d 2자리보다 작으면 공백으로 2자리 확보
		printf("\n");
	}
	printf("\n");
}

int findRow(int A[], int key) {
	for (int c = 0; c < COLS; c++)
		if (A[c] == key)
			return c;
	return -1;
}

int findMatrix(int A[][COLS], int key) {
	
	int r = 0;
	int index;
	while (r < ROWS) {
		index = findRow(A[r], key);
		if (index >= 0) {
			printf("(%d, %d)에서 %d 발견\n", r, index, key);
			return;
		}
		else {
			r++;
		}
	}
	printf("not found\n");
	return;
}

void main() {
	int A[ROWS][COLS];
	srand(time(NULL));	//없으면, 계속 같은 난수 발생
	makeArray(A);
	printArray(A);

	int key;
	printf("Input a key value : ");
	scanf_s("%d", &key);

	findMatrix(A, key);
}