#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

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

//맨 앞에 추가
void addFirst(LinkedListType* L, int item) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = item;
	node->link = L->head;
	L->head = node;
}

//pos에 추가
void add(LinkedListType* L, int pos, int item) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	ListNode* before = L->head;
	for (int i = 0; i < pos - 1; i++)
		before = before->link;
	node->data = item;
	node->link = before->link;
	before->link = node;
}

//addLast(my)
void addLast(LinkedListType* L, int item) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	ListNode* before = L->head;
	while (before->link!=NULL) {
		before = before->link;
	}
	node->data = item;
	node->link = before->link;
	before->link = node;
}


//remove, removeFirst, remove List 해보기

//특정 위치의 노드 반환
int get(LinkedListType* L, int pos) {
	ListNode* p = L->head;
	for (int i = 1; i < pos; i++) {
		p = p->link;
	}
	return p->data;
}

//특정 위치의 노드값 바꾸기
int set(LinkedListType* L, int pos, int item) {
	ListNode* p = L->head;
	for (int i = 1; i < pos; i++)
		p = p->link;
	p->data = item;
}

//전체 리스트 출력
void printList(LinkedListType* L) {
	for (ListNode* p = L->head; p != NULL; p = p->link)
		printf("[%d] -> ", p->data);
	printf("NULL\n");
}

void main() {
	LinkedListType list;
	init(&list);

	addFirst(&list, 10); printList(&list);
	addFirst(&list, 20); printList(&list);
	addFirst(&list, 30); printList(&list);
	printf("\n");
	add(&list, 1, 40); printList(&list);
	add(&list, 1, 50); printList(&list);
	add(&list, 3, 60); printList(&list);
	printf("\n");
	addLast(&list, 70); printList(&list);
	addLast(&list, 80); printList(&list);
	addLast(&list, 90); printList(&list);
	int pos;
	printf("\n몇 번 노드의 값을 반환할까요? ");
	scanf_s("%d", &pos, sizeof(4));
	printf("%d번 노드의 값은 %d\n", pos, get(&list, pos));

}