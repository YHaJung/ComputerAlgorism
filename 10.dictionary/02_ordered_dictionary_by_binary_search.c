#include <stdio.h>
#include <time.h>

#define SIZE 10

typedef struct {
	int key;
	char value[10];
}element;

typedef struct {
	element dict[SIZE];
	int size;
}DictType;

void init(DictType* d) {
	d->size = 0;
}

void insertKey(DictType* d) {
	for (int i = 0; i < SIZE; i++) {
		d->dict[i].key = rand() % 30 + 1;
		for (int j = 0; j < i; j++){   // À¯ÀÏ Å°
			if (d->dict[i].key == d->dict[j].key)
				i--;
		}
	}
}

void insertValue(DictType* d) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < 5; j++) {   //make random string - length 5
			d->dict[i].value[j] = rand() % 26 + 97;
		}
		d->size++;
	}
}

void makeDict(DictType* d) {
	insertKey(d);
	insertValue(d);
}

void printDict(DictType* d) {
	printf("key value\n==========\n");
	for (int i = 0; i < d->size; i++) {
		printf("%2d ", d->dict[i].key);
		for (int j = 0; j < 5; j++) {
			printf("%c", d->dict[i].value[j]);
		}
		printf("\n");
	}
}

void insertion_sort(DictType* d) {
	int i, j;
	element item;
	for (i = 0; i < d->size; i++) {
		item = d->dict[i];
		for (j = i - 1; j >= 0 && d->dict[j].key > item.key; j--) {
			d->dict[j + 1] = d->dict[j];
		}
		d->dict[j + 1] = item;
	}
}


void main() {
	DictType d;
	init(&d);

	srand(time(NULL));
	makeDict(&d);
	printDict(&d);

	getchar();
	printf("\n");

	insertion_sort(&d);
	printDict(&d);

	getchar();
}