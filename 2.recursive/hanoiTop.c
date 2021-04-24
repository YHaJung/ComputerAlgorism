#include <stdio.h>
#include <stdlib.h>

#define SIZE 15

void hanoi(int n, int from, int aux, int to) {
	if (n == 1) {
		printf("move disk %d from %c to %c\n", n, from, to);
		return;
	}
	
	hanoi(n - 1, from, to, aux);
	printf("move disk %d from %c to %c\n", n, from, to);
	hanoi(n - 1, aux, from, to);
}

void main() {
	hanoi(4, 'A', 'B', 'C');
}