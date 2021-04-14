#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 100

//Èü
typedef struct {
	int heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

void initHeap(HeapType* h) {
	h->heap_size = 0;
}
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

//½ºÅÃ
typedef struct {
	int stack[MAX_ELEMENT];
	int top;
}Stack;
void initStack(Stack* s) {
	s->top = -1;
}
int isEmpty(Stack* s) {
	if (s->top == -1) return 1;
	else return 0;
}
void push(int data, Stack* s) {
	if (s->top + 1 < MAX_ELEMENT) {
		s->top++;
		s->stack[s->top] = data;
	}
}
int pop(Stack* s) {
	if (isEmpty(s) == 0) {
		int result = s->stack[s->top];
		s->top--;
		return result;
	}
	else {
		return -1;
	}
}

//find last of heap
void binaryExpansion(int i, Stack* s) {
	while (i >= 2) {
		push(i % 2, s);
		i /= 2;
	}
	push(i, s);
}
int findLastNode(int n, HeapType* h) {
	int value = -1;
	int parent = 1;
	int child = 2;

	Stack stack;
	initStack(&stack);
	binaryExpansion(n, &stack);
	pop(&stack);
	while (isEmpty(&stack) == 0) {
		int bit = pop(&stack);
		if (bit == 0) {
			value = h->heap[child];
		}
		else {
			value = h->heap[++child];
		}
		parent = child;
		child = parent * 2;
	}
	return value;
}

//Ãâ·Â
void printHeap(HeapType* h) {
	for (int i = 1; i <= h->heap_size; i++) {
		printf("[%d] ", h->heap[i]);
	}
	printf("\n");
}
void printStack(Stack* s) {
	for (int i = 0; i <= s->top; i++) {
		printf("[%d] ", s->stack[i]);
	}
	printf("\n");
}

void main() {
	HeapType heap;
	initHeap(&heap);

	//»ğÀÔ
	insertItem(&heap, 13);
	insertItem(&heap, 3);
	insertItem(&heap, 5);
	insertItem(&heap, 2);
	insertItem(&heap, 4);
	insertItem(&heap, 1);
	insertItem(&heap, 7);
	insertItem(&heap, 4);
	insertItem(&heap, 8);
	printHeap(&heap);
	//find last
	int lastNum = findLastNode(heap.heap_size, &heap);
	printf("last number : %d\n", lastNum);
}