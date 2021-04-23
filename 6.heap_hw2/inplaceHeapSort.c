#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
#define SWAP(x, y, t) ((t)=(x), (x)=(y), (y)=(t))

typedef struct {
	int data[SIZE];
	int size;
}Heap;

void init(Heap* h) {
	h->size = 0;
}

void printHeap(Heap* h) {
	for (int i = 1; i <= h->size; i++)
		printf("%d ", h->data[i]);
	printf("\n");
}

//최대힙
void upHeap(Heap* h) {
	int save = h->data[h->size];
	int pos = h->size;
	while (pos / 2 > 0 && h->data[pos / 2] < save) {
		h->data[pos] = h->data[pos / 2];
		pos /= 2;
	}
	h->data[pos] = save;		
}
void insert(Heap* h, int x) {
	h->size++;
	h->data[h->size] = x;
	upHeap(h);
}


void downHeap(Heap* h, int n) {
	int save = h->data[1];
	int parent = 1;
	int child = 2;
	while (child <= n) {
		if (child < n && h->data[child] < h->data[child + 1])
			child++;
		if (save > h->data[child])
			break;
		h->data[parent] = h->data[child];
		parent = child;
		child = parent * 2;
	}
	h->data[parent] = save;
}


void inplaceSort(Heap* h) {
	int temp;
	int heapsize = h->size;
	while (heapsize > 1) {
		SWAP(h->data[1], h->data[heapsize], temp);
		heapsize--;
		downHeap(h, heapsize);
	}
	
}

//prof - removeMin 있다고 가정
/*
void inplaceSort(Heap* h) {
	int size = h->size;
	int key;
	for (int i = 0; i < size; i++) {
		key = removeMin(h);
		h->data[h->size + 1] = key;
	}
	h->size = size;//이건 내가 추가.. 이렇게 하면 전체 크기 유지
}*/

void main() {
	Heap h;
	init(&h);

	insert(&h, 4);
	insert(&h, 7);
	insert(&h, 3);
	insert(&h, 5);
	insert(&h, 9);
	insert(&h, 1);

	printHeap(&h);

	inplaceSort(&h);
	printHeap(&h);
	
}