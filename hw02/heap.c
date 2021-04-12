#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENT 100

typedef struct {
	int heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

void init(HeapType *h) {
	h->heap_size = 0;
}


//삽입
void upHeap(HeapType* h) {
	int i = h->heap_size;
	int key = h->heap[i];
	while ((i != 1) && (key < h->heap[i / 2])) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = key;
}
void insertItem(HeapType* h, int key) {
	h->heap_size += 1;
	h->heap[h->heap_size] = key;
	upHeap(h);
}

//삭제
void downHeap(HeapType* h) {
	int temp = h->heap[1];
	int parent = 1, child = 2;

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
int removeMin(HeapType* h) {
	int key = h->heap[1];
	h->heap[1] = h->heap[h->heap_size];
	h->heap_size -= 1;
	downHeap(h);
	return key;
}


//정렬
void heapSort(HeapType* h, int list[]) {
	HeapType heap;
	init(&heap);
	//원래 차례로 insertItem 사용하여, list로 불러온 걸 heap으로 만들어야 함.
	//여기선 앞에서 삽입으로 만들어둔 힙이 있으므로 그냥 사용
	for (int i = 1; i <= h->heap_size; i++) {
		heap.heap[i] = h->heap[i];
		heap.heap_size++;
	}
	for (int i = 1; i <= h->heap_size; i++) {
		list[i] = removeMin(&heap);
	}
}


//출력
void printHeap(HeapType* h) {
	for (int i = 1; i <= h->heap_size; i++) {
		printf("[%d] ", h->heap[i]);
	}
	printf("\n");
}
void printArray(int list[], int n) {
	for (int i = 1; i <= n; i++)
		printf("[%d] ", list[i]);
	printf("\n");
}

void main() {
	HeapType heap;
	int list[MAX_ELEMENT] = { 0 };
	init(&heap);

	//삽입
	insertItem(&heap, 5);
	insertItem(&heap, 3);
	insertItem(&heap, 7);
	insertItem(&heap, 4);
	insertItem(&heap, 1);
	insertItem(&heap, 4);
	insertItem(&heap, 8);
	insertItem(&heap, 2);

	printHeap(&heap);

	//정렬
	heapSort(&heap, list);
	printArray(list, heap.heap_size);

	//삭제
	printHeap(&heap);
	printf("deleted key : %d\n", removeMin(&heap));
	printHeap(&heap);
}