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

//sort dictionary
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

//recursive way
int rFindElement(DictType* d, int key, int l, int r) {
	int mid = (l + r) / 2;

	if (l > r)
		return -1;

	if (key == d->dict[mid].key) {
		return mid;
	}
	else if (key < d->dict[mid].key) {
		return rFindElement(d, key, l, mid - 1);
	}
	else {
		return rFindElement(d, key, mid + 1, r);
	}
}

//repeatation way
int FindElement(DictType* d, int key, int l, int r) {
	int mid;
	while (l < r) {
		mid = (l + r) / 2;
		if (key == d->dict[mid].key) {
			return mid;
		}
		else if (key < d->dict[mid].key) {
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	return -1;
}


//delete
element removeElement(DictType* d, int key) {
	int index = FindElement(d, key, 0, d->size - 1);
	if (index == -1) {
		printf("삭제할 요소가 없습니다.\n");
		return;
	}
	else {
		//mycode
		/*
		d->dict[index] = d->dict[d->size - 1];
		d->size--;
		insertion_sort(d);
		*/
		//professor code
		element item = d->dict[index];
		for (int i = index; i < d->size - 1; i++)
			d->dict[i] = d->dict[i + 1];
		d->size--;
		return item;
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
	//int index = FindElement(&d, key, 0, d.size - 1);
	if (index == -1)
		printf("\n검색에 실패하였습니다.\n");
	else {
		printf("\n위치 %d에서 키 : %d, 값 : ", index + 1, key);
		for (int i = 0; i < 5; i++) {
			printf("%c", d.dict[index].value[i]);
		}
		printf("이 검색되었음\n");
	}
	getchar();

	printf("\n삭제할 키값을 입력 : ");
	scanf_s("%d", &key);
	removeElement(&d, key);
	printDict(&d);
}