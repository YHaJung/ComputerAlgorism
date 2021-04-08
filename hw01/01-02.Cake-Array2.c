//cake 촛불 쓰기 문제 - 배열ver.2
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define JUMP 3

//현 상태 확인을 위해, 케이크 출력
void printCake(int A[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
}

//캐익 생성
void buildList(int A[], int n) {
	for (int r = 0; r < n; r++)
		A[r] = r + 1;
}

//remove함수
void remove1(int A[], int n, int pos) {
	//exception 넣어야 함

	int item = A[pos];
	for (int i = pos + 1; i <= n - 1; i++)
		A[i - 1] = A[i];
	n--;
}

//촛불 끄기 진행
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

//문제 시작
int candle(int A[], int n, int k) {
	buildList(A, n);
	return runSimulation(A, n, k);
}

void main() {
	int A[SIZE];
	int n = SIZE;
	int k = JUMP;
	printf("촛불 : %d, 간격 : %d\n", n, k);
	int result = candle(A, n, k);
	printf("결과 : %d\n", result);
}