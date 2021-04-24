#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE 16

typedef struct {
	int heap[MAXSIZE+1];
	int heap_size;
}HeapType;

void init(HeapType* h) {
	h->heap_size = 0;
}

void printHeap(HeapType* h) {
	int i = 1;
	for (int j = 1; i <= MAXSIZE; j *= 2) {
		for (int k = 0; k < j && i <= h->heap_size; k++) {
			printf("[%d] ", h->heap[i++]);
		}
		printf("\n");
	}
	printf("----------\n");
}

void downHeap(HeapType* h, int root) {
	int parent = root;
	int child = parent * 2;
	int save = h->heap[root];

	while (child <= h->heap_size) {
		if (child<h->heap_size && h->heap[child] > h->heap[child + 1])
			child++;
		if (h->heap[child] > save)
			break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = save;
}

void buildHeap(HeapType* h, int root) {
	for (int i = h->heap_size / 2; i > 0; i--) {
		downHeap(h, i);
		printHeap(h);
	}
}


void main() {
	HeapType h;
	init(&h);
	srand(time(NULL));
	for (int i = 1; i <= MAXSIZE; i++)
		h.heap[i] = rand() % 100;
	h.heap_size = MAXSIZE;

	printHeap(&h);
	buildHeap(&h, 1);
	printHeap(&h);
}