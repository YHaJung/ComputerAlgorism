//cake �к� ���� ���� - �迭ver.2
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define JUMP 3

//�� ���� Ȯ���� ����, ����ũ ���
void printCake(int A[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
}

//ĳ�� ����
void buildList(int A[], int n) {
	for (int r = 0; r < n; r++)
		A[r] = r + 1;
}

//remove�Լ�
void remove1(int A[], int n, int pos) {
	//exception �־�� ��

	int item = A[pos];
	for (int i = pos + 1; i <= n - 1; i++)
		A[i - 1] = A[i];
	n--;
}

//�к� ���� ����
int runSimulation(int A[], int n, int k) {
	int r = 0;
	printCake(A, n);
	while (n > 1) {
		r = (r + k) % n;
		remove1(A, n, r);
		n--;
		printCake(A, n);
	}
	return A[0];
}

//���� ����
int candle(int A[], int n, int k) {
	buildList(A, n);
	return runSimulation(A, n, k);
}

void main() {
	int A[SIZE];
	int n = SIZE;
	int k = JUMP;
	printf("�к� : %d, ���� : %d\n", n, k);
	int result = candle(A, n, k);
	printf("��� : %d\n", result);
}