#include <stdio.h>
#include <stdlib.h>

void peroid(int X[], int S[], int n) {
	for (int i = 0; i < n; i++) {
		int s = 1;
		while (s <= i && X[i - s] <= X[i])
			s = s + 1;
		S[i] = s;
	}
	return;
}

void printArray(int X[], int n) {
	for (int i = 0; i < n; i++)
		printf("%d ", X[i]);
	printf("\n");
}

void main() {
	int X[6] = { 60, 30 , 40, 20, 50, 30 };
	int S[6];
	peroid(X, S, 6);
	printArray(S, 6);
}
