#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

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

//�� �տ� �߰�
void addFirst(LinkedListType* L, int item) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = item;
	node->link = L->head;
	L->head = node;
}

//pos�� �߰�
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


//remove, removeFirst, remove List �غ���

//Ư�� ��ġ�� ��� ��ȯ
int get(LinkedListType* L, int pos) {
	ListNode* p = L->head;
	for (int i = 1; i < pos; i++) {
		p = p->link;
	}
	return p->data;
}

//Ư�� ��ġ�� ��尪 �ٲٱ�
int set(LinkedListType* L, int pos, int item) {
	ListNode* p = L->head;
	for (int i = 1; i < pos; i++)
		p = p->link;
	p->data = item;
}

//��ü ����Ʈ ���
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
	printf("\n�� �� ����� ���� ��ȯ�ұ��? ");
	scanf_s("%d", &pos, sizeof(4));
	printf("%d�� ����� ���� %d\n", pos, get(&list, pos));

}