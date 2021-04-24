#include <stdio.h>
#include <stdlib.h>

#define ROWS 4
#define COLS 5

void printArray(int A[][COLS], int n, int m) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf("%2d ", A[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void spiral(int A[][COLS], int n, int m) {
	int left = 0, right = m - 1;
	int top = 0, bottom = n - 1;
	int k = 1;

	int i, j;
	while (left <= right && top <= bottom) {
		for (j = left; j <= right; j++)
			A[top][j] = k++;
		top++;
		printArray(A, ROWS, COLS);

		for (i = top; i <= bottom; i++)
			A[i][right] = k++;
		right--;
		printArray(A, ROWS, COLS);
		
		for (j = right; j >= left; j--)
			A[bottom][j] = k++;
		bottom--;
		printArray(A, ROWS, COLS);

		for (i = bottom; i >= top; i--)
			A[i][left] = k++;
		left++;
		printArray(A, ROWS, COLS);
	}
}

void main() {
	int list[ROWS][COLS] = {0};
	spiral(list, ROWS, COLS);
}