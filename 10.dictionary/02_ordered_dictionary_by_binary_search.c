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
		for (int j = 0; j < i; j++){   // 유일 키
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

int rFindElement(DictType* d, int key, int l, int r) {
	int mid = (l + r) / 2;

	if (l > r)
		return -1;

	if (d->dict[mid].key == key) {
		return mid;
	}
	else if (d->dict[mid].key > key) {
		return rFindElement(d, key, l, mid - 1);
	}
	else {
		return rFindElement(d, key, mid + 1, r);
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

	int key;
	printf("\n검색할 키값을 입력: ");
	scanf_s("%d", &key);
	int index = rFindElement(&d, key, 0, d.size - 1);
	if (index == -1)
		printf("\n검색에 실패하였습니다.\n");
	else {
		printf("\n위치 %d에서 키 : %d, 값 : ", index + 1, key);
		for (int i = 0; i < 5; i++) {
			printf("%c", d.dict[index].value[i]);
		}
		printf("이 검색되었음\n");
	}
		

}