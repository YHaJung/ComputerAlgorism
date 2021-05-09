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
		for (int j = 0; j < i; j++) {   // À¯ÀÏ Å°
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


int findElement(int A[], int key, int left, int right) {

}


void main() {
	DictType dict;
	init(&dict);

	srand(time(NULL));
	makeDict(&dict);
	printDict(&dict);
}