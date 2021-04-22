#include <stdio.h>
#include <stdlib.h>

#define SIZE 6

void spans(int X[], int S[], int n) {
	int s;
	for (int i = 0; i < n; i++) {
		s = 1;
		while (s <= i && X[i - s] <= X[i])
			s++;
		S[i] = s;
	}
}

void printArray(int X[], int n) {
	for (int i = 0; i < n; i++)
		printf("%d ", X[i]);
	printf("\n");
}

void main() {
	int X[SIZE] = { 60, 30 , 40, 20, 50, 30 };
	int S[SIZE] = { 0 };
	spans(X, S, SIZE);
	printArray(S, 6);
}
