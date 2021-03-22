#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct {
	int V[SIZE];
	int n;
}ArrayList;

void init(ArrayList* L) {
	L->n = 0;
}

void traverse(ArrayList* L) {
	for (int i = 0; i < L->n; i++)
		printf("[%d] ", L->V[i]);
}

void main() {
	ArrayList list;

	init(&list);

	printf("test\n");
}