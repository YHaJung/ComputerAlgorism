#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE 15

typedef struct {
	int heap[MAXSIZE+1];
	int heap_size;
}HeapType;

void init(HeapType* h) {
	h->heap_size = 0;
}

void printHeap(HeapType* h) {
	int i = 1;
	for (int j = 1; i <= h->heap_size; j*=2) {
		for (int k = 0; k < j && i<=h->heap_size; k++) {
			printf("[%d] ", h->heap[i++]);
		}
		printf("\n");
	}
	printf("----------\n");
}

void downHeap(HeapType* h, int root) {
	int temp = h->heap[root];
	int parent = root, child = root*2;

	while (child <= h->heap_size) {
		if ((child < h->heap_size) && (h->heap[child] > h->heap[child + 1])) {
			child++;
		}
		if (temp <= h->heap[child]) {
			break;
		}
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
}

/*
void buildHeap(HeapType* h, int root) {
	if (root * 2 > h->heap_size)
		return;
	buildHeap(h, root*2);
	buildHeap(h, root * 2 + 1);
	downHeap(h, root);
}*/
//prof
void buildHeap(HeapType* h, int root) {
	if (root > h->heap_size)
		return;
	if (root * 2 <= h->heap_size)
		buildHeap(h, root * 2);
	if (root * 2 + 1 <= h->heap_size)
		buildHeap(h, root * 2 + 1);
	downHeap(h, root);
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