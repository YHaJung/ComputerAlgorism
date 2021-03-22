//cake �к� ���� ���� - ���� ���� ����Ʈ
#include <stdio.h>
#include <stdlib.h>


//��� ����ü
typedef struct ListNode {
	int data;
	struct ListNode* link;
}ListNode;

//��� ������(�Ϲ� �����ͷ� �ص� ��. but �ϰ��� �ֱ� ���� ����ü ���)
typedef struct {
	ListNode* head;
}LinkedListType;

//����Ʈ ���� ����
void init(LinkedListType* L) {
	L->head = NULL;
}


//�� ���� Ȯ���� ����, ����ũ ���
void printList(LinkedListType* L) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	for (p = L->head; p->link != L->head; p = p->link)
		printf("[%d] -> ", p->data);
	printf("[%d]\n", p->data);
}

//ĳ�� ����
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


//�к� ���� ����
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

//���� ����
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

	printf("�к� : %d, ���� : %d\n", n, k);
	int result = candle(&list, n, k);
	printf("��� : %d\n", result);
}