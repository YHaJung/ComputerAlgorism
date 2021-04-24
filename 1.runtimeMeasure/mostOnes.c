#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 8
#define COLS 8
#define ROWS 8

void printArray(int A[][SIZE], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
	printf("----------\n");
}

int mostOnes1(int A[][SIZE], int n) {
	int i=0, j=0;
	int row = -1;
	while (1) {
		while (A[i][j] == 1) {
			j++;
			if (j == COLS - 1)
				return i;
		}
		row = 1;
		while (A[i][j] == 0) {
			i++;
			if (i == COLS - 1)
				return row;
		}
	}
}

//my
void mostOnes2(int A[][SIZE], int n) {
	int r = 0, c = 0;
	int maxRow = -1;
	while (r < n && c < n) {
		if (A[r][c] == 1) {
			c++;
			maxRow = r;
		}
		else {
			r++;
		}
	}
	printf("max row : %d\n", maxRow);
}

void main() {
	int list[SIZE][SIZE] = { 0 };
	srand(time(NULL));
	int num, i, j;
	for (i = 0; i < SIZE; i++) {
		num = rand() % SIZE;
		for (j = 0; j < num; j++) {
			list[i][j] = 1;
		}
	}
	printArray(list, SIZE);
	int row = mostOnes1(list, SIZE);
	printf("max row : %d\n", row);
}
