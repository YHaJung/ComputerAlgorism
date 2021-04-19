#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5

int findRow(int x, int A[], int n) {
	
	int i = 0;
	while (i < n) {
		if (A[i] == x) {
			return i;
		}
		else {
			
			i++;
		}
	}
	return -1;
}

int findMatrix(int x, int A[MAXSIZE][MAXSIZE], int n) {
	
	int r = 0;
	int i;
	while (r < n) {
		i = findRow(x, A[r], n);
		if (i >= 0) {
			printf("(%d, %d)\n", r, i);
			return;
		}
		else {
			r++;
		}
	}
	printf("not found");
	return;
}

void main() {
	int A[MAXSIZE][MAXSIZE] = {
		{101,102,103,104,105},
		{106,107,108,109,110},
		{111,112,113, 114, 115},
		{116, 117, 118, 119, 120},
		{216, 217, 218, 29, 220}
	};
	findMatrix(108, A, 5);
}