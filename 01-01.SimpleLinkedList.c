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
	ListNode* last = L->head;
	while (last->link!=NULL) {
		last = last->link;
	}
	node->data = item;
	node->link = last->link;
	last->link = node;
}


//remove, removeFirst, remove List 해보기
void removeFirst(LinkedListType* L) {
	L->head = L->head->link;
}
void remove1(LinkedListType* L, int pos) {
	ListNode* before = L->head;
	for (int i = 0; i < pos - 1; i++)
		before = before->link;
	before->link = before->link->link;
}
void removeLast(LinkedListType* L) {
	ListNode* last = L->head;
	if (last->link == NULL) {
		L->head = NULL;
	}
	else {
		while (last->link->link != NULL)
			last = last->link;
		last->link = NULL;
	}
}

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

	printf("\nadd first\n");
	addFirst(&list, 10); printList(&list);
	addFirst(&list, 20); printList(&list);
	addFirst(&list, 30); printList(&list);
	printf("\nadd\n");
	add(&list, 1, 40); printList(&list);
	add(&list, 1, 50); printList(&list);
	add(&list, 3, 60); printList(&list);
	printf("\nadd last\n");
	addLast(&list, 70); printList(&list);
	addLast(&list, 80); printList(&list);
	addLast(&list, 90); printList(&list);

	printf("\n");
	int pos1;
	printf("\n몇 번 노드의 값을 반환할까요? ");
	scanf_s("%d", &pos1, sizeof(4));
	printf("%d번 노드의 값은 %d\n", pos1, get(&list, pos1));
	int pos2, num;
	printf("\n몇 번 노드의 값을 바꿀까요? ");
	scanf_s("%d", &pos2, sizeof(4));
	printf("어떤 값으로 바꿀까요? ");
	scanf_s("%d", &num, sizeof(4)*100);
	set(&list, pos2, num);
	printList(&list);
	
	printf("\nremove first\n");
	removeFirst(&list); printList(&list);
	removeFirst(&list); printList(&list);
	printf("\nremove\n");
	remove1(&list, 1); printList(&list);
	remove1(&list, 1); printList(&list);
	remove1(&list, 3); printList(&list);
	printf("\nremove last\n");
	removeLast(&list); printList(&list);
	removeLast(&list); printList(&list);
	removeLast(&list); printList(&list);
	removeLast(&list); printList(&list);

}