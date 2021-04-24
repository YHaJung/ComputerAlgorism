#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

void printArray(int A[][SIZE], int n) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%2d ", A[i][j]);
		}
		printf("\n");
	}
}

void zigzag(int A[][SIZE], int n) {
	int i, j;
	int k = 1;
	for (i = 0; i < n; i++) {
		if (i % 2 == 0) {
			for (j = 0; j < n; j++) {
				A[i][j] = k++;
			}
		}
		else{
			for (j = n-1; j >=0; j--) {
				A[i][j] = k++;
			}
		}
		
	}
}

void main() {
	int list[SIZE][SIZE];
	zigzag(list, SIZE);
	printArray(list, SIZE);

}