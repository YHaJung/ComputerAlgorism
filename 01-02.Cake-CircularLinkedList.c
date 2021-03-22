//cake 촛불 쓰기 문제 - 원형 연결 리스트
#include <stdio.h>
#include <stdlib.h>


//노드 구조체
typedef struct ListNode {
	int data;
	struct ListNode* link;
}ListNode;

//헤드 포인터(일반 포인터로 해도 됨. but 일관성 주기 위해 구조체 사용)
typedef struct {
	ListNode* head;
}LinkedListType;

//리스트 새로 시작
void init(LinkedListType* L) {
	L->head = NULL;
}


//현 상태 확인을 위해, 케이크 출력
void printList(LinkedListType* L) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	for (p = L->head; p->link != L->head; p = p->link)
		printf("[%d] -> ", p->data);
	printf("[%d]\n", p->data);
}

//캐익 생성
LinkedListType* buildList(LinkedListType* L, int n) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	L->head = p;
	p->data = 1;
	for (int i = 2; i < n + 1; i++) {
		p->link = (ListNode*)malloc(sizeof(ListNode));
		p = p->link;
		p->data = i;
	}
	p->link = L->head;
	return L;
}


//촛불 끄기 진행
int runSimulation(LinkedListType* L, int n, int k) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	
	p = L->head;

	ListNode* pnext = (ListNode*)malloc(sizeof(ListNode));
	while (p != p->link) {
		for (int i = 0; i < k - 1; i++) {
			p = p->link;
		}
		pnext = p->link;
		p->link = pnext->link;
		p = p->link;
		if (pnext == L->head) {
			L->head = p;
		}
		free(pnext);
		printList(L);
	}

	return p->data;
}

//문제 시작
int candle(LinkedListType* L, int n, int k) {
	buildList(L, n);
	printList(L);
	return runSimulation(L, n, k);
}

void main() {
	LinkedListType list;
	init(&list);

	int n = 10;
	int k = 3;

	printf("촛불 : %d, 간격 : %d\n", n, k);
	int result = candle(&list, n, k);
	printf("결과 : %d\n", result);
}