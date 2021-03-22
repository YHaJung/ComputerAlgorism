#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct {
	int V[SIZE];	//배열의 값들
	int n;			//요소의 개수
}ArrayList;

void init(ArrayList* L) {
	L->n = 0;
}

//접근 method
void traverse(ArrayList* L) {
	for (int i = 0; i < L->n; i++)
		printf("[%d] ", L->V[i]);	//배열 v의 i번째 값을 차래로 출력
	printf("\n");
}

//add함수
void add(ArrayList* L, int pos, int item) {

	if (L->n == SIZE) {
		printf("fullListException...\n");
		exit(1);
	}

	//invalidPosException.... 0<= pos <= L->n
	//우리가 코딩할 땐 해야함. 지금은 일단 단순 생략

	for (int i = L->n - 1; i >= pos; i--)
		L->V[i + 1] = L->V[i];
	L->V[pos] = item;
	L->n++;
}

//remove함수
int remove(ArrayList* L, int pos) {
	//exception 넣어야 함

	int item = L->V[pos];
	for (int i = pos + 1; i <= L->n - 1; i++)
		L->V[i - 1] = L->V[i];
	L->n--;

	return item;
}

void main() {
	ArrayList list;

	init(&list);

	add(&list, 0, 10); traverse(&list);
	add(&list, 0, 20); traverse(&list);
	add(&list, 1, 30); traverse(&list);
	add(&list, 1, 40); traverse(&list);
	add(&list, 3, 50); traverse(&list);

	//getchar(); 이거 있으면 무한 루프처럼 안되는데, 뭐하는 함수지..?
	remove(&list, 1); traverse(&list);
	remove(&list, 2); traverse(&list);
}